import serial
import config_pb2
import motor_pb2
import sensor_pb2
import status_pb2
from struct import *

state = 0
# 0 - wait
# 1 - A 0x41
# 2 - N 0x4E
# 3 - S 0x53
# 4 - I 0x49
# 5 - SIZE
# 6 - SIZE

with serial.Serial('/dev/cu.wchusbserial1410', 9600, timeout=100) as ser:

    hexsize = ''
    buffer = ''
    messagelength = 6

    while state < messagelength:

        c = ser.read()

        if state == 0 and ord(c) == 0x41:
            state = 1
            print "A"
            continue

        if state == 1:
            if ord(c) == 0x4E:
                state = 2
                print "N"
                continue
            else:
                state = 0

        if state == 2:
            if ord(c) == 0x53:
                state = 3
                print "S"
                continue
            else:
                state = 0

        if state == 3:
            if ord(c) == 0x49:
                state = 4
                print "I"
                hexsize = ''
                continue
            else:
                state = 0

        if state == 4:
            hexsize += c
            state = 5
            print "size"
            continue

        if state == 5:
            hexsize += c
            state = 6
            buffer = ''
            messagelength += unpack('<H', hexsize)[0]
            print "size"
            continue

        if state > 5:
            state += 1
            buffer += c

    print len(buffer)

    status = status_pb2.Status()
    status.ParseFromString(buffer)
    print status


