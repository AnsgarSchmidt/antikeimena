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

volatile uint32_t mycounter = 0;

uint8_t uplink_send_buffer[BUFFERSIZE];

void uplink_setup(void){
  Serial.begin(UPLINK_SPEED);
}

void uplink_sendStatus(void){

    antikeimena_Status status_pb = antikeimena_Status_init_zero;

    status_pb.version       = 12;
    status_pb.uptime        = millis();
    status_pb.sensorInError = 14;
    status_pb.debug         = mycounter;

    pb_ostream_t stream = pb_ostream_from_buffer(uplink_send_buffer, sizeof(uplink_send_buffer));
    pb_encode(&stream, antikeimena_Status_fields, &status_pb);

    uint16_t mysize = stream.bytes_written;

    Serial.write("ANSI");
    Serial.flush();

    Serial.write(STATUS_MESSAGE);
    Serial.flush();

    Serial.write( (mysize     ) & 0xFF); // low
    Serial.write( (mysize >> 8) & 0xFF); // high
    Serial.flush();

    for(uint32_t i = 0; i < mysize; i++) {
        Serial.write(uplink_send_buffer[i]);
    }
    Serial.flush();
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

    Serial.write("ANSI");
    Serial.flush();

    Serial.write(SENSOR_MESSAGE);
    Serial.flush();

    Serial.write( (mysize     ) & 0xFF); // low
    Serial.write( (mysize >> 8) & 0xFF); // high
    Serial.flush();

    for(uint32_t i = 0; i < mysize; i++) {
        Serial.write(uplink_send_buffer[i]);
    }
    Serial.flush();

}

void uplink_checkReceive(void) {
  while (Serial.available()) {
    Serial.read();
    mycounter++;
  }
}
