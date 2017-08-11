import serial
import time
import config_pb2
import motor_pb2
import sensor_pb2
import status_pb2
from   struct     import *

# 0     -> wait
# 1     -> A 0x41
# 2     -> N 0x4E
# 3     -> S 0x53
# 4     -> I 0x49
# 5     -> MESSAGE TYPE
# 6     -> SIZE
# 7     -> SIZE
# 8-end -> DATA


def debugData():
    with serial.Serial('/dev/cu.wchusbserial1410', 9600, timeout=10000) as ser:
        state         = 0
        hexsize       = ''
        buffer        = ''
        messagelength = 7
        messagetype   = 0

        while state < messagelength:

            c = ser.read()

            if state == 0:
                if ord(c) == 0x41:
                    state += 1
                    print "A"
                    continue
                else:
                    state = 0

            if state == 1:
                if ord(c) == 0x4E:
                    state += 1
                    print "N"
                    continue
                else:
                    state = 0

            if state == 2:
                if ord(c) == 0x53:
                    state += 1
                    print "S"
                    continue
                else:
                    state = 0

            if state == 3:
                if ord(c) == 0x49:
                    state += 1
                    print "I"
                    hexsize = ''
                    continue
                else:
                    state = 0

            if state == 4:
                messagetype = ord(c)
                state += 1
                print "MessageType: %d" % messagetype
                continue

            if state == 5:
                hexsize += c
                state += 1
                print "size"
                continue

            if state == 6:
                hexsize += c
                state += 1
                buffer = ''
                messagelength += unpack('<H', hexsize)[0]
                print "size:%d" % (messagelength-7)
                continue

            if state > 6:
                state += 1
                buffer += c

        print "Buffersize:%d" % len(buffer)
        time.sleep(0.1)

        if messagetype == 4:
            print "STATUS:"
            status = status_pb2.Status()
            status.ParseFromString(buffer)
            print status

        if messagetype == 3:
            print "Sensor:"
            sensor = sensor_pb2.Sensor()
            sensor.ParseFromString(buffer)
            print sensor

        if messagetype == 2:
            print "Motor:"
            motor = motor_pb2.Motor()
            motor.ParseFromString(buffer)
            print motor

        if messagetype == 1:
            print "Config:"
            config = config_pb2.Config()
            config.ParseFromString(buffer)
            print config

if __name__ == "__main__":
    for i in range(100):
        debugData()