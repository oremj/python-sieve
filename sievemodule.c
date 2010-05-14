#include <Python.h>
#include "sieve.h"

static PyObject *
sieve_sieve(PyObject *self, PyObject *args)
{
    char *primes;
    long long upto;
    int i;
    PyObject *prime_list;

    if (!PyArg_ParseTuple(args, "L", &upto))
        return NULL;
    primes = sieve(upto);

    prime_list = PyList_New(0);
    for(i=0; i <= upto; i++) {
        if(primes[i])
            PyList_Append(prime_list, Py_BuildValue("L", i));
    }

    free(primes);
    primes = NULL;
    
    return prime_list;
}

static PyMethodDef SieveMethods[] = {
    {"sieve",  sieve_sieve, METH_VARARGS,
     "Return list of primes."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initsieve(void)
{
    (void) Py_InitModule("sieve", SieveMethods);
}
