# Pycephes

Pycephes provides you with a Python interface to the HCephes library (a reformatted version of Netlib Cephes). It's based on [NCephes](https://github.com/limix/ncephes/tree/master) and updated to be compatible with modern Numba releases (tested on 0.57.0).

## Why?
I wanted to use SciPy special functions in Numba functions running in nopython mode. That was not possible. As many of SciPy's special functions are just wrappers of Cephes functions, I made my own wrappers that were compatible with Numba.

While PyCephes is much more bare-bones, a lazy ad hoc experiment indicates that there are some performance improvements, see [this notebook](/workspaces/pycephes/test.ipynb).

# No argument validation
Pycephes performs no argument validation in the binding wrappers. The reason is because validating just *one* argument could double the execution time, so I'd much prefer to leave the responsibility, and freedom, to you. For quality of life, I hope to add typing and pydocs in the future. In the meantime, refer to [FUNCTIONS.txt](./FUNCTIONS.txt) or [interface.h](pycephes/interface.h) to see parameter and return types.

In case you provide invalid arguments, Hcephes will print an error message and return a fallback value. To be clear, an argument can be invalid despite the data type being correct. For example, the binomial distribution function demands that arguments must be positive, with parameter `p` ranging from 0 to 1 and `k` being smaller than `n`. Again, refer to [FUNCTIONS.txt](./FUNCTIONS.txt).

## Cephes function bindings
See [FUNCTIONS.txt](./FUNCTIONS.txt)

I haven't tested most of them, but as long as the parameters and return types are scalar-valued they should work. Passing Numpy arrays require some more work.

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
