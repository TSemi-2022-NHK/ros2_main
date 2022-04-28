# generated from rosidl_generator_py/resource/_idl.py.em
# with input from socketcan_interface_msg:msg/SocketcanIF.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'candata'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SocketcanIF(type):
    """Metaclass of message 'SocketcanIF'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('socketcan_interface_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'socketcan_interface_msg.msg.SocketcanIF')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__socketcan_if
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__socketcan_if
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__socketcan_if
            cls._TYPE_SUPPORT = module.type_support_msg__msg__socketcan_if
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__socketcan_if

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SocketcanIF(metaclass=Metaclass_SocketcanIF):
    """Message class 'SocketcanIF'."""

    __slots__ = [
        '_canid',
        '_candlc',
        '_candata',
    ]

    _fields_and_field_types = {
        'canid': 'int16',
        'candlc': 'uint8',
        'candata': 'uint8[8]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 8),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.canid = kwargs.get('canid', int())
        self.candlc = kwargs.get('candlc', int())
        if 'candata' not in kwargs:
            self.candata = numpy.zeros(8, dtype=numpy.uint8)
        else:
            self.candata = numpy.array(kwargs.get('candata'), dtype=numpy.uint8)
            assert self.candata.shape == (8, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.canid != other.canid:
            return False
        if self.candlc != other.candlc:
            return False
        if all(self.candata != other.candata):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def canid(self):
        """Message field 'canid'."""
        return self._canid

    @canid.setter
    def canid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'canid' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'canid' field must be an integer in [-32768, 32767]"
        self._canid = value

    @property
    def candlc(self):
        """Message field 'candlc'."""
        return self._candlc

    @candlc.setter
    def candlc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'candlc' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'candlc' field must be an unsigned integer in [0, 255]"
        self._candlc = value

    @property
    def candata(self):
        """Message field 'candata'."""
        return self._candata

    @candata.setter
    def candata(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'candata' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 8, \
                "The 'candata' numpy.ndarray() must have a size of 8"
            self._candata = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 8 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'candata' field must be a set or sequence with length 8 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._candata = numpy.array(value, dtype=numpy.uint8)