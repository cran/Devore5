#include <R.h>
#include <Rdefines.h>

extern double F77_NAME(dnrm2)(int *, double *, int *);

SEXP dnorm2(SEXP x)
{
    int one = 1, n;
    SEXP val;

    PROTECT(x = AS_NUMERIC(x)); n = LENGTH(x);
    PROTECT(val = NEW_NUMERIC(1));
    NUMERIC_POINTER(val)[0] =
        F77_CALL(dnrm2)(&n, NUMERIC_POINTER(x), &one);
    UNPROTECT(2);
    return(val);
}
