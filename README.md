# Pycephes

Pycephes provides you with a Python interface to the HCephes library (a reformatted version of Netlib Cephes). It's based on [NCephes](https://github.com/limix/ncephes/tree/master) and updated to be compatible with modern Numba releases.

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
4. ```python
   import pycephes
   bdtr = pycephes.bdtr(4, 6, 0.3)

   # You can even use the function in Numba-jitted functions running in nopython mode:
   @nb.njit
    def nb_bdtr(k, n, p):
        return pycephes.bdtr(k, n, p)

    bdtr = nb_bdtr(4, 6, 0.3)
   ```
