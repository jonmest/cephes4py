import _pycephes
import logging
from importlib.metadata import version
import sys

python_version = sys.version_info

# Register with Numba
numba_installed = False
try:
    import numba
    numba_installed = True
except ModuleNotFoundError as _:
    pass

if numba_installed:
    try:
        from numba.core.typing.cffi_utils import register_module as _register_module
        _register_module(_pycephes)
    except ModuleNotFoundError as _:
        logging.warn("Failed to register Cephes bindings to Numba. You will be unable to call the bindings in Numba-jitted functions in nopython mode.")

from _pycephes.lib import hcephes_bdtr as bdtr