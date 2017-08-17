import serial
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


def debugData(ser):
    state         = 0
    hexsize       = ''
    messagetype   = 0
    messagelength = 0

    while state < 7:

        c = ser.read()

        if state == 0:
            if ord(c) == 0x41:
                state += 1
                print ("A")
                continue
            else:
                state = 0

        if state == 1:
            if ord(c) == 0x4E:
                state += 1
                print ("N")
                continue
            else:
                state = 0

        if state == 2:
            if ord(c) == 0x53:
                state += 1
                print ("S")
                continue
            else:
                state = 0

        if state == 3:
            if ord(c) == 0x49:
                state += 1
                print ("I")
                continue
            else:
                state = 0

        if state == 4:
            messagetype = ord(c)
            state += 1
            print ("MessageType: %d" % messagetype)
            continue

        if state == 5:
            hexsize = c
            state += 1
            print ("size")
            continue

        if state == 6:
            hexsize += c
            state += 1
            messagelength = unpack('<H', hexsize)[0]
            print ("size:%d" % messagelength)
            continue

    message = ser.read(messagelength)
    print ("Buffersize:%d" % len(message))

    if messagetype == 4:
        print ("STATUS:")
        status = status_pb2.Status()
        status.ParseFromString(message)
        print (status)

    if messagetype == 3:
        print ("Sensor:")
        sensor = sensor_pb2.Sensor()
        sensor.ParseFromString(message)
        print (sensor)

    if messagetype == 2:
        print ("Motor:")
        motor = motor_pb2.Motor()
        motor.ParseFromString(message)
        print (motor)

    if messagetype == 1:
        print ("Config:")
        config = config_pb2.Config()
        config.ParseFromString(message)
        print (config)

def sendMotor(ser, left, right):
    motor = motor_pb2.Motor()
    motor.speed_left  = left
    motor.speed_right = right
    message = motor.SerializeToString()
    ser.write(0x41) # A
    ser.write(0x4E) # N
    ser.write(0x53) # S
    ser.write(0x49) # I
    ser.write(0x2)  # MOTOR
    ser.write(pack('<H', len(message)))
    ser.write(message)
    ser.flush()

if __name__ == "__main__":
    with serial.Serial('/dev/cu.wchusbserial1410', 115200, timeout=10000) as ser:
        for i in range(42):
            debugData(ser)
            sendMotor(ser, 23, 42)
