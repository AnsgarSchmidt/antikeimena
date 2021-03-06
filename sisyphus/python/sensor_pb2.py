# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: sensor.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='sensor.proto',
  package='antikeimena',
  syntax='proto3',
  serialized_pb=_b('\n\x0csensor.proto\x12\x0b\x61ntikeimena\"\xcb\x02\n\x06Sensor\x12\x15\n\rodometry_left\x18\x01 \x01(\r\x12\x16\n\x0eodometry_right\x18\x02 \x01(\r\x12\x17\n\x0f\x62\x61ttery_voltage\x18\x03 \x01(\x02\x12\x13\n\x0btemperature\x18\x04 \x01(\x02\x12\x15\n\rultrasonic_01\x18\x05 \x01(\r\x12\x15\n\rultrasonic_02\x18\x06 \x01(\r\x12\x15\n\rultrasonic_03\x18\x07 \x01(\r\x12\x15\n\rultrasonic_04\x18\x08 \x01(\r\x12\x15\n\rultrasonic_05\x18\t \x01(\r\x12\x15\n\rultrasonic_06\x18\n \x01(\r\x12\x15\n\rultrasonic_07\x18\x0b \x01(\r\x12\x15\n\rultrasonic_08\x18\x0c \x01(\r\x12\x15\n\rultrasonic_09\x18\r \x01(\r\x12\x15\n\rultrasonic_10\x18\x0e \x01(\rb\x06proto3')
)




_SENSOR = _descriptor.Descriptor(
  name='Sensor',
  full_name='antikeimena.Sensor',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='odometry_left', full_name='antikeimena.Sensor.odometry_left', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='odometry_right', full_name='antikeimena.Sensor.odometry_right', index=1,
      number=2, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='battery_voltage', full_name='antikeimena.Sensor.battery_voltage', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='temperature', full_name='antikeimena.Sensor.temperature', index=3,
      number=4, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_01', full_name='antikeimena.Sensor.ultrasonic_01', index=4,
      number=5, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_02', full_name='antikeimena.Sensor.ultrasonic_02', index=5,
      number=6, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_03', full_name='antikeimena.Sensor.ultrasonic_03', index=6,
      number=7, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_04', full_name='antikeimena.Sensor.ultrasonic_04', index=7,
      number=8, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_05', full_name='antikeimena.Sensor.ultrasonic_05', index=8,
      number=9, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_06', full_name='antikeimena.Sensor.ultrasonic_06', index=9,
      number=10, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_07', full_name='antikeimena.Sensor.ultrasonic_07', index=10,
      number=11, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_08', full_name='antikeimena.Sensor.ultrasonic_08', index=11,
      number=12, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_09', full_name='antikeimena.Sensor.ultrasonic_09', index=12,
      number=13, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ultrasonic_10', full_name='antikeimena.Sensor.ultrasonic_10', index=13,
      number=14, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=30,
  serialized_end=361,
)

DESCRIPTOR.message_types_by_name['Sensor'] = _SENSOR
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Sensor = _reflection.GeneratedProtocolMessageType('Sensor', (_message.Message,), dict(
  DESCRIPTOR = _SENSOR,
  __module__ = 'sensor_pb2'
  # @@protoc_insertion_point(class_scope:antikeimena.Sensor)
  ))
_sym_db.RegisterMessage(Sensor)


# @@protoc_insertion_point(module_scope)
