// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.h"
#include "socketcan_interface_msg/msg/detail/socketcan_if__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool socketcan_interface_msg__msg__socketcan_if__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("socketcan_interface_msg.msg._socketcan_if.SocketcanIF", full_classname_dest, 53) == 0);
  }
  socketcan_interface_msg__msg__SocketcanIF * ros_message = _ros_message;
  {  // canid
    PyObject * field = PyObject_GetAttrString(_pymsg, "canid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->canid = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // candlc
    PyObject * field = PyObject_GetAttrString(_pymsg, "candlc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->candlc = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // candata
    PyObject * field = PyObject_GetAttrString(_pymsg, "candata");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT8);
      Py_ssize_t size = 8;
      uint8_t * dest = ros_message->candata;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * socketcan_interface_msg__msg__socketcan_if__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SocketcanIF */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("socketcan_interface_msg.msg._socketcan_if");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SocketcanIF");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  socketcan_interface_msg__msg__SocketcanIF * ros_message = (socketcan_interface_msg__msg__SocketcanIF *)raw_ros_message;
  {  // canid
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->canid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "canid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // candlc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->candlc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "candlc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // candata
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "candata");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT8);
    assert(sizeof(npy_uint8) == sizeof(uint8_t));
    npy_uint8 * dst = (npy_uint8 *)PyArray_GETPTR1(seq_field, 0);
    uint8_t * src = &(ros_message->candata[0]);
    memcpy(dst, src, 8 * sizeof(uint8_t));
    Py_DECREF(field);
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}