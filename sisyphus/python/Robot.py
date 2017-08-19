import Queue
import serial
import time
import threading
import config_pb2
import motor_pb2
import sensor_pb2
import status_pb2
from   struct     import *

class ReceiveThread(threading.Thread):

    def __init__(self, ser, receiveQueue):
        threading.Thread.__init__(self)
        self.setDaemon(True)
        self._ser          = ser
        self._queue = receiveQueue

    def run(self):

        state         = 0
        hexsize       = ''
        messagetype   = 0
        messagelength = 0

        while True:

            while state < 7:

                c = self._ser.read()

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

            message = self._ser.read(messagelength)
            print ("Buffersize:%d" % len(message))

            if messagetype == 4:
                print ("STATUS:")
                status = status_pb2.Status()
                status.ParseFromString(message)
                print (status)
                self._queue.put(status)

            if messagetype == 3:
                print ("Sensor:")
                sensor = sensor_pb2.Sensor()
                sensor.ParseFromString(message)
                print (sensor)
                self._queue.put(sensor)

            if messagetype == 2:
                print ("Motor:")
                motor = motor_pb2.Motor()
                motor.ParseFromString(message)
                print (motor)
                self._queue.put(motor)

            if messagetype == 1:
                print ("Config:")
                config = config_pb2.Config()
                config.ParseFromString(message)
                print (config)
                self._queue.put(config)


class SendThread(threading.Thread):

    def __init__(self, ser, sendQueue):
        threading.Thread.__init__(self)
        self.setDaemon(True)
        self._ser          = ser
        self._queue = sendQueue

    def run(self):
        while True:
            command = self._queue.get()
            message_type = 0

            if "Config" == command.DESCRIPTOR.name:
                message_type = '\x01'

            if "Motor" == command.DESCRIPTOR.name:
                message_type = '\x02'

            if "Sensor" == command.DESCRIPTOR.name:
                message_type = '\x03'

            if "Status" == command.DESCRIPTOR.name:
                message_type = '\x04'

            if message_type > 0:
                self._ser.write('\x41')  # A
                self._ser.write('\x4E')  # N
                self._ser.write('\x53')  # S
                self._ser.write('\x49')  # I
                message = command.SerializeToString()
                self._ser.write(message_type)
                self._ser.write(pack('<H', len(message)))
                self._ser.write(message)
                print (command)
                print ("HEXDUMP:" + ' '.join(hex(ord(ime)) for ime in message))
                self._ser.flush()


class Robot(threading.Thread):

    def __init__(self):
        threading.Thread.__init__(self)
        self.setDaemon(True)
        self._sendQueue    = Queue.Queue()
        self._receiveQueue = Queue.Queue()
        self._robotSerial  = serial.Serial("/dev/tty.usbmodem1411", 9600)
        self._receiver     = ReceiveThread(self._robotSerial, self._receiveQueue)
        self._sender       = SendThread(self._robotSerial, self._sendQueue)

    def set_speed(self, left, right):
        motor = motor_pb2.Motor()
        motor.speed_left  = left
        motor.speed_right = right
        self._sendQueue.put(motor)

    def run(self):
        self._receiver.start()
        self._sender.start()


if __name__ == "__main__":
    print ("Debug")
    r = Robot()
    r.start()
    r.set_speed(23, 42)
    time.sleep(10)

