
/* DEALLOC */
static void
MyPy_BaseClass_dealloc(MyPy_BaseClass* self){
   // deallocate class members and class itself
   Py_TYPE(self)->tp_free((PyObject*)self);
}

/* NEW */
static PyObject *
MyPy_BaseClass_new(PyTypeObject *type, PyObject *args, PyObject *kwds){

   MyPy_BaseClass* self;
   self = (MyPy_BaseClass *)type->tp_alloc(type, 0);

   // Init vars if any ...
   if (self != NULL){
      // Nothing ... yay
   }

   return (PyObject*) self;

}


/* INIT */
static int
MyPy_BaseClass_init(MyPy_BaseClass *self, PyObject *args, PyObject *kwds){

   // If you set any variable values or parse constructor arguments, do it here.
   return 0;

}


/* FUNCTION some_base_function */
static PyObject *
MyPy_BaseClass_some_base_function(MyPy_BaseClass* self, PyObject *args, PyObject *kwds){

   char* argument = NULL;
   char* optional_argument = NULL;
   static char *kwlist[] = {"arg","optional_arg",NULL};
   if (! PyArg_ParseTupleAndKeywords(args, kwds, "s|s", kwlist, &argument, &optional_argument)){ // the | makes the string argument optional
      // Id rather raise money than raising errors
      PyErr_SetString(PyExc_AttributeError,"One argument must be given as str, the other is optional as str too.");
      return NULL;
   }

   // dunno what to do ...
   if(optional_argument != NULL){
      return Py_BuildValue("s",optional_argument);
   } else {
      return Py_BuildValue("s",argument);
   }

}
