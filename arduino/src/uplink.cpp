#include <Arduino.h>
#include "uplink.h"
#include "main.h"
#include "usonic.h"

extern "C" {
    #include "pb.h"
    #include "pb_encode.h"
    #include "pb_decode.h"
    #include "status.pb.h"
    #include "sensor.pb.h"
    #include "odometry.h"
    #include "battery.h"
}

uplink_states uplink_state         = WAITING_FOR_A;
uint16_t      uplink_message_size  = 0;
uint8_t       uplink_message_type  = 0;
uint8_t       uplink_message_index = 0;
uint8_t       uplink_receive_buffer[BUFFERSIZE];
uint8_t       uplink_send_buffer[BUFFERSIZE];
uint32_t      uplink_debug         = 0;

void uplink_setup(void){
  Serial1.begin(UPLINK_SPEED);
}

void uplink_sendStatus(void){

    antikeimena_Status status_pb = antikeimena_Status_init_zero;

    status_pb.version       = 12;
    status_pb.uptime        = millis();
    status_pb.sensorInError = 14;
    status_pb.debug         = uplink_debug;

    pb_ostream_t stream = pb_ostream_from_buffer(uplink_send_buffer, sizeof(uplink_send_buffer));
    pb_encode(&stream, antikeimena_Status_fields, &status_pb);

    uint16_t mysize = stream.bytes_written;

    Serial1.write("ANSI");
    Serial1.flush();

    Serial1.write(STATUS_MESSAGE);
    Serial1.flush();

    Serial1.write( (mysize     ) & 0xFF); // low
    Serial1.write( (mysize >> 8) & 0xFF); // high
    Serial1.flush();

    for(uint32_t i = 0; i < mysize; i++) {
        Serial1.write(uplink_send_buffer[i]);
    }
    Serial1.flush();
}

void uplink_sendSensor(void){

    antikeimena_Sensor sensor_pb = antikeimena_Sensor_init_zero;

    sensor_pb.odometry_left   = odometry_get_left_counter();
    sensor_pb.odometry_right  = odometry_get_right_counter();
    sensor_pb.battery_voltage = battery_voltage;
    sensor_pb.ultrasonic_01   = ultrasonic_distance[0];
    sensor_pb.ultrasonic_02   = ultrasonic_distance[1];
    sensor_pb.ultrasonic_03   = ultrasonic_distance[2];
    sensor_pb.ultrasonic_04   = ultrasonic_distance[3];
    sensor_pb.ultrasonic_05   = ultrasonic_distance[4];
    sensor_pb.ultrasonic_06   = ultrasonic_distance[5];
    sensor_pb.ultrasonic_07   = ultrasonic_distance[6];
    sensor_pb.ultrasonic_08   = ultrasonic_distance[7];
    sensor_pb.ultrasonic_09   = ultrasonic_distance[8];
    sensor_pb.ultrasonic_10   = ultrasonic_distance[9];

    pb_ostream_t stream = pb_ostream_from_buffer(uplink_send_buffer, sizeof(uplink_send_buffer));
    pb_encode(&stream, antikeimena_Sensor_fields, &sensor_pb);

    uint16_t mysize = stream.bytes_written;

    Serial1.write("ANSI");
    Serial1.flush();

    Serial1.write(SENSOR_MESSAGE);
    Serial1.flush();

    Serial1.write( (mysize     ) & 0xFF); // low
    Serial1.write( (mysize >> 8) & 0xFF); // high
    Serial1.flush();

    for(uint32_t i = 0; i < mysize; i++) {
        Serial1.write(uplink_send_buffer[i]);
    }
    Serial1.flush();

}

void uplink_checkReceive(void) {

  while (Serial1.available()) {

    uint8_t c = Serial1.read();

    if (uplink_state == WAITING_FOR_A){
        if (c == 0x41){
            uplink_debug = 23;
            uplink_state = WAITING_FOR_N;
        }else{
            uplink_state = WAITING_FOR_A;
        }
    }

    if (uplink_state == WAITING_FOR_N){

        if (c == 0x4E){
            uplink_debug = 24;
            uplink_state = WAITING_FOR_S;
        }else{
            uplink_state = WAITING_FOR_A;
        }
    }

    if (uplink_state == WAITING_FOR_S){
        if (c == 0x53){
            uplink_debug = 25;
            uplink_state = WAITING_FOR_I;
        }else{
            uplink_state = WAITING_FOR_A;
        }
    }

    if (uplink_state == WAITING_FOR_I){
        if (c == 0x49){
            uplink_debug = 26;
            uplink_state = WAITING_FOR_TYPE;
        }else{
            uplink_state = WAITING_FOR_A;
        }
    }

    if (uplink_state == WAITING_FOR_TYPE){
        uplink_message_type = c;
        uplink_state = WAITING_FOR_SIZE_L;
    }

    if (uplink_state == WAITING_FOR_SIZE_L){
        uplink_message_size = (uint16_t) c;
        uplink_state = WAITING_FOR_SIZE_H;
    }

    if (uplink_state == WAITING_FOR_SIZE_H){
        uint16_t val = (uint16_t) c;
        val <<= 8;
        uplink_message_size = val & uplink_message_size;
        uplink_state = WAITING_FOR_MESSAGE;
    }

    if (uplink_state == WAITING_FOR_MESSAGE){
        uplink_receive_buffer[uplink_message_index] = c;
        uplink_message_index++;

        if(uplink_message_index > uplink_message_size){
            uplink_state = WAITING_FOR_A;
        }
    }

  }
}
