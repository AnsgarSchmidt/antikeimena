#include <Arduino.h>
#include "uplink.h"
#include "main.h"

extern "C" {
    #include "pb.h"
    #include "pb_encode.h"
    #include "status.pb.h"
}

uint8_t uplink_send_buffer[BUFFERSIZE];

void uplink_setup(void){
  Serial.begin(9600);
}

void uplink_sendStatus(void){

    pb_ostream_t stream = pb_ostream_from_buffer(uplink_send_buffer, sizeof(uplink_send_buffer));
    pb_encode(&stream, antikeimena_Status_fields, &status_pb);

    uint16_t s = antikeimena_Status_size;

    Serial.write("ANSI");

    Serial.write( (s     ) & 0xFF); // low
    Serial.write( (s >> 8) & 0xFF); // high

    for(uint32_t i = 0; i < antikeimena_Status_size; i++) {
        Serial.write(uplink_send_buffer[i]);
    }

}

void uplink_sendSensor(void){

}