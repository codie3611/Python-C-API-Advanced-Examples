
#ifndef INHERITANCE_CLASS_HPP
#define INHERITANCE_CLASS_HPP

// includes
#include <Python.h>
#include "base_class.hpp"

#ifdef __cplusplus
extern "C" {
#endif

  /* OBJECT */
  typedef struct {
      MyPy_BaseClass super; // <----- PUTTING THIS FIRST INHERITS THE BASE PYTHON CLASS!!!
      // Own c-variables:
      // e.g int x = 0;
  } MyPy_InheritanceClass;


  /* DEALLOC */
  static void
  MyPy_InheritanceClass_dealloc(MyPy_InheritanceClass* self);

  /* NEW */
  static PyObject *
  MyPy_InheritanceClass_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

  /* INIT */
  static int
  MyPy_InheritanceClass_init(MyPy_InheritanceClass *self, PyObject *args, PyObject *kwds);

  /* METHOD TABLE */
  static PyMethodDef MyPy_InheritanceClass_methods[] = {
	{NULL}  /* Sentinel */
  };

  /* TYPE ... whatever */
  static PyTypeObject MyPy_InheritanceClass_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "MyPy_InheritanceClass",          /* tp_name */
    sizeof(MyPy_InheritanceClass),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)MyPy_InheritanceClass_dealloc, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
    Py_TPFLAGS_BASETYPE,       /* tp_flags */ 
    "MyPy_InheritanceClass",   /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    MyPy_InheritanceClass_methods,    /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    &MyPy_BaseClass_Type,      /* tp_base */ // <------ GIVE THE BASE_CLASS TYPE
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) MyPy_InheritanceClass_init, /* tp_init */
    0,                         /* tp_alloc */
    MyPy_InheritanceClass_new, /* tp_new */
    };

#ifdef __cplusplus
}
#endif


#endif // BASE_CLASS_HPP
