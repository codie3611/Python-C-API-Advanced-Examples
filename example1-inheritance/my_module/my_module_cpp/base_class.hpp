
#ifndef BASE_CLASS_HPP
#define BASE_CLASS_HPP

// includes
#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif

  /* OBJECT */
  typedef struct {
      PyObject_HEAD // do not append a semicolon! <----- IMPORTANT: ONLY NEEDED IN A PYTHON BASE CLASS!!!
      // Own c-variables:
      // e.g int x = 0;
  } MyPy_BaseClass;


  /* DEALLOC */
  static void
  MyPy_BaseClass_dealloc(MyPy_BaseClass* self);

  /* NEW */
  static PyObject *
  MyPy_BaseClass_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

  /* INIT */
  static int
  MyPy_BaseClass_init(MyPy_BaseClass *self, PyObject *args, PyObject *kwds);

  /* FUNCTION some_base_function */
  static PyObject *
  MyPy_BaseClass_some_base_function(MyPy_BaseClass* self, PyObject *args, PyObject *kwds);

  /* METHOD TABLE */
  static PyMethodDef MyPy_BaseClass_methods[] = {
   {"some_base_function", (PyCFunction) MyPy_BaseClass_some_base_function, METH_VARARGS, "Description no one ever reads."},
	{NULL}  /* Sentinel */
  };

  /* TYPE ... whatever */
  static PyTypeObject MyPy_BaseClass_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "MyPy_BaseClass",          /* tp_name */
    sizeof(MyPy_BaseClass),    /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)MyPy_BaseClass_dealloc, /* tp_dealloc */
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
    Py_TPFLAGS_BASETYPE,        /* tp_flags */ // <------ IMPORTANT, MAKES CLASS INHERITABLE!!!
    "MyPy_BaseClass",          /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    MyPy_BaseClass_methods,    /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) MyPy_BaseClass_init, /* tp_init */
    0,                         /* tp_alloc */
    MyPy_BaseClass_new,             /* tp_new */
    };

#ifdef __cplusplus
}
#endif


#endif // BASE_CLASS_HPP
