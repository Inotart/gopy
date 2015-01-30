/*
  C stubs for package py_hi.
  gopy-gen -lang=python hi

  File is generated by gopy-gen. Do not edit.
*/

#include "_cgo_export.h"

#include "Python.h"

/* stdlib */
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <complex.h>

// helpers for CGo runtime

typedef struct { char *p; int n; } _cgopy_gostring_;
typedef struct { void* array; unsigned int len; unsigned int cap; } _cgopy_goslice_;


extern void crosscall2(void (*fn)(void *, int), void *, int);
extern void _cgo_allocate(void *, int);
extern void _cgo_panic(void *, int);

static void *_cgopy_goallocate(size_t len) {
  struct {
    size_t len;
    void *ret;
  } a;
  a.len = len;
  crosscall2(_cgo_allocate, &a, (int) sizeof a);
  return a.ret;
}

static void _cgopy_gopanic(const char *p) {
  struct {
    const char *p;
  } a;
  a.p = p;
  crosscall2(_cgo_panic, &a, (int) sizeof a);
}

static GoString _cgopy_makegostringn(const char *p, size_t l) {
  _cgopy_gostring_ ret;
  ret.p = (char*)_cgopy_goallocate(l + 1);
  memcpy(ret.p, p, l);
  ret.n = l;
  return *(GoString*)(&ret);
}

static GoString _cgopy_makegostring(const char *p) {
  _cgopy_gostring_ ret;
  size_t l;
  l = strlen(p);
  ret.p = (char*)_cgopy_goallocate(l);
  memcpy(ret.p, p, l);
  ret.n = l;
  return *(GoString*)(&ret);
}

static char* _cgopy_makecstring(const GoString *gostr) {
  _cgopy_gostring_ *s = (_cgopy_gostring_*)(gostr);
  char* cstr = (char*)malloc((s->n+1) * sizeof(char));
  memcpy(cstr, s->p, s->n);
  cstr[s->n] = '\0';
  return cstr;
}


/* pythonization of: hi.Add */
static PyObject*
gopy_Add(PyObject *self, PyObject *args) {
	GoInt c_i;
	GoInt c_j;
	GoInt c_gopy_ret;
	
	if (!PyArg_ParseTuple(args, "ii", &c_i, &c_j)) {
		return NULL;
	}
	
	
	c_gopy_ret = GoPy_Add(c_i, c_j);
	
	return Py_BuildValue("i", c_gopy_ret);
}


/* pythonization of: hi.Hello */
static PyObject*
gopy_Hello(PyObject *self, PyObject *args) {
	const char* cgopy_s;
	GoString c_s;
	
	if (!PyArg_ParseTuple(args, "s", (GoString*)(&cgopy_s))) {
		return NULL;
	}
	
	c_s = _cgopy_makegostring(cgopy_s);
	
	GoPy_Hello(c_s);
	
	Py_INCREF(Py_None);
	return Py_None;
}


/* pythonization of: hi.Hi */
static PyObject*
gopy_Hi(PyObject *self, PyObject *args) {
	
	GoPy_Hi();
	
	Py_INCREF(Py_None);
	return Py_None;
}

static PyMethodDef GoPy_hi_Methods[] = {
	{"Add", gopy_Add, METH_VARARGS, "doc for: hi.Add"},
	{"Hello", gopy_Hello, METH_VARARGS, "doc for: hi.Hello"},
	{"Hi", gopy_Hi, METH_VARARGS, "doc for: hi.Hi"},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
inithi(void)
{
    (void) Py_InitModule3("hi", GoPy_hi_Methods, "FIXME(sbinet): documentation for package hi");
}
