# Pycephes

Pycephes is a Python interface to the HCephes library, which is a reformatted version of Netlib Cephes. It provides a convenient way to access the functionality of the HCephes library within Python. Pycephes has been updated to ensure compatibility with modern Numba releases (specifically tested on version 0.57.0).

## Motivation
The motivation behind developing Pycephes was the need to use SciPy special functions within Numba functions running in nopython mode. Unfortunately, this was not possible due to compatibility issues. Since many of SciPy's special functions are actually wrappers of Cephes functions, I decided to create my own wrappers that were compatible with Numba.

Although Pycephes is a more stripped-down version, I have conducted a preliminary experiment that suggests some performance improvements. You can refer to [this notebook](/workspaces/pycephes/test.ipynb) for more details.

# No Argument Validation
It is important to note that Pycephes does not perform argument validation in the binding wrappers. This decision was made because validating even a single argument could potentially double the execution time. Therefore, I have chosen to leave the responsibility and freedom of argument validation to you. Please refer to [FUNCTIONS.txt](./FUNCTIONS.txt) or [interface.h](pycephes/interface.h) to see the expected parameter and return types.

In the event that you provide invalid arguments, Hcephes will display an error message and return a fallback value. Please keep in mind that an argument can be considered invalid even if the data type is correct. For example, the binomial distribution function requires arguments to be positive, with the parameter `p` ranging from 0 to 1 and `k` being smaller than `n`. Once again, please consult [FUNCTIONS.txt](./FUNCTIONS.txt) for more information.

## Cephes Function Bindings
For a list of available Cephes functions and their descriptions, please refer to [FUNCTIONS.txt](./FUNCTIONS.txt). Please note that I have not tested all of the functions extensively, but as long as the parameters and return types are scalar-valued, they should work properly. If you intend to pass Numpy arrays as arguments, additional work may be required.

## Installation
To install Pycephes, please follow these steps:

1. Install the [hcephes](https://github.com/limix/hcephes) binary. It is recommended to compile it from source, but you will need Cmake to do so. You can use the following command to install it:
   ```sh
   curl -fsSL https://git.io/JerYI | GITHUB_USER=limix GITHUB_PROJECT=hcephes bash
   ```
2. Navigate to the root directory of this repository.
3. Install the Pycephes package by running the following command:
   ```sh
   pip install .
   ```
4. You're all set! You can now use Pycephes in your Python code:
   ```python
   import pycephes
   
   # Example usage
   bdtr = pycephes.bdtr(4, 6, 0.3)

   # You can even use the function in Numba-jitted functions running in nopython mode:
   @nb.njit
   def nb_bdtr(k, n, p):
     return pycephes.bdtr(k, n, p)

   bdtr = nb_bdtr(4, 6, 0.3)
   ```
