#include <Arduino.h>
#include "uplink.h"
#include "main.h"

extern "C" {
    #include "pb.h"
    #include "pb_encode.h"
    #include "status.pb.h"
}

void sendPB(void){
    uint8_t buffer[256];

    pb_ostream_t       stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    pb_encode(&stream, antikeimena_Status_fields, &status);

    uint16_t s = antikeimena_Status_size;

    Serial.write("ANSI");

    Serial.write( (s     ) & 0xFF); // low
    Serial.write( (s >> 8) & 0xFF); // high

    for(uint32_t i = 0; i < antikeimena_Status_size; i++) {
        Serial.write(buffer[i]);
    }

}
