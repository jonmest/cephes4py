from cffi import FFI

CDEF = '''\
double hcephes_bdtr(int k, int n, double p);
'''

include_dirs = ["/usr/include", "/usr/local/include"]
library_dirs = ["/usr/lib", "/usr/local/lib"]

ffibuilder = FFI()
ffibuilder.cdef(CDEF)
ffibuilder.set_source(
    '_hcephes',
    '#include "hcephes.h"',
    libraries=["hcephes"],
    library_dirs=library_dirs,
    include_dirs=include_dirs,
    language="c"
)

ffibuilder.compile(verbose=True)