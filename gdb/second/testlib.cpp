#ifdef DEBUG
#include <python2.7_d/Python.h>
#else
#include <python2.7/Python.h>
#endif
 
using namespace std;
 
PyObject* CFuncEntry(PyObject* self,PyObject* args)
{
 
    PyObject*  datalist = NULL;
    PyArg_ParseTuple( args,"O",&datalist );
 
    int rst = 0;
    for ( int i = 0; i < PyList_Size(datalist); ++i )
    {
        int val = PyInt_AsLong(PyList_GetItem( datalist,i ));
        rst += val;
    }
 
    return Py_BuildValue("i", rst);
}
 
PyMODINIT_FUNC initCFuncEntry(void)
{
    static PyMethodDef methods[] = {
    {"CFuncEntry", (PyCFunction)CFuncEntry, METH_VARARGS, "test lib"},
    {NULL, NULL, 0, NULL}
    };
 
    Py_InitModule("CFuncEntry", methods);
}

