# Pycephes

Pycephes provides you with a Python interface to the HCephes library (a reformatted version of Netlib Cephes). It's based on [NCephes](https://github.com/limix/ncephes/tree/master) and updated to be compatible with modern Numba releases (tested on 0.57.0).

## Why?
I wanted to use SciPy special functions in Numba functions running in nopython mode. That was not possible. As many of SciPy's special functions or just wrappers of Cephes functions, I made my own wrappers that were compatible with Numba.

While PyCephes is much more bare-bones, a lazy ad hoc experiment indicates that there are some performance improvements, see [this notebook](/workspaces/pycephes/test.ipynb).

## Supported Cephes functions
See [FUNCTIONS.txt](./FUNCTIONS.txt)                                 

## Installation
1. Install the [hcephes](https://github.com/limix/hcephes) binary. I recommend compiling it from source - but you'll need Cmake.
   ```sh
   curl -fsSL https://git.io/JerYI | GITHUB_USER=limix GITHUB_PROJECT=hcephes bash
   ```
2. Enter the root of this repository
3. Install the package:
   ```sh
   pip install .
   ```
4. Go nuts:
    ```python
   import pycephes
   bdtr = pycephes.bdtr(4, 6, 0.3)

   # You can even use the function in Numba-jitted functions running in nopython mode:
   @nb.njit
   def nb_bdtr(k, n, p):
     return pycephes.bdtr(k, n, p)

   bdtr = nb_bdtr(4, 6, 0.3)
   ```
