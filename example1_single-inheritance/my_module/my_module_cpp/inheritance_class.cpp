
/* DEALLOC */
static void
MyPy_InheritanceClass_dealloc(MyPy_InheritanceClass* self){
   // deallocate class members and class itself
   Py_TYPE(self)->tp_free((PyObject*)self);
}

/* NEW */
static PyObject *
MyPy_InheritanceClass_new(PyTypeObject *type, PyObject *args, PyObject *kwds){

   MyPy_InheritanceClass* self;
   self = (MyPy_InheritanceClass *)type->tp_alloc(type, 0);

   // Init vars if any ...
   if (self != NULL){
      // Nothing ... yay
   }

   return (PyObject*) self;

}


/* INIT */
static int
MyPy_InheritanceClass_init(MyPy_InheritanceClass *self, PyObject *args, PyObject *kwds){

   // If you set any variable values or parse constructor arguments, do it here.
   return 0;

}
