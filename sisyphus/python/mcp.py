import status_pb2

status = status_pb2.Status()
status.version = 1
status.uptime = 2
status.sensorInError = 3

print status