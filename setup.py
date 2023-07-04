from setuptools import setup

setup(
    name="pycephes",
    version="0.0.2",
    py_modules=["pycephes"],
    install_requires=["cffi"],
    setup_requires=["cffi"],
    cffi_modules=["build_hcephes.py:ffibuilder"],
)