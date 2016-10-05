

// includes
#include <Python.h>
#include "base_class.hpp"
#include "inheritance_class.hpp"


#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************/
/*                    C L A S S E S                    */
/*******************************************************/

// We simply copy the source files in here
#include "base_class.cpp"
#include "inheritance_class.cpp"


/*******************************************************/
/*                      M O D U L E                    */
/*******************************************************/


static PyObject *
some_module_function(PyObject *self, PyObject *args)
{
 return Py_None;
}


/* MODULE codie function table */
static PyMethodDef my_module_cpp_methods[] = {
  {"some_module_function", some_module_function, METH_VARARGS,"Again a description no one will ever care about."},
  {NULL, NULL, 0, NULL}        /* Sentinel */
};


/* MODULE INIT */
void
initmy_module_cpp(void) // The name after init MUST be the same name as in setup.py
{
  PyObject* m;

  // Constructor
  if (PyType_Ready(&MyPy_BaseClass_Type) < 0)
    return;


  // Init Module
  m = Py_InitModule3("my_module_cpp", my_module_cpp_methods, // The name after init MUST be the same name as in setup.py
                     "yay a module description.");

  // Import numpy if needed
  //import_array();

  if (m == NULL)
    // PY3 return NULL;
    return;

  // Initialize Classes
  Py_INCREF(&MyPy_BaseClass_Type);
  PyModule_AddObject(m, "BaseClass", (PyObject *)&MyPy_BaseClass_Type); // This name is used for the import command!!!!

}


#ifdef __cplusplus
}
#endif
