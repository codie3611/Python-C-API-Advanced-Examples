
import os
from setuptools import setup, Extension

# create a C++ extension
src_files = ['my_module/my_module_cpp/python_wrapper.cpp']
my_module_cpp = Extension("my_module_cpp",src_files) # replaces the folder by a binary .pyd

# setup command
setup(name = "example_inheritance",
      license = "GNU GPL v3",
      packages = (['my_module']),
      package_dir={'my_module': 'my_module'},
      ext_package='my_module', # where to place c extensions
      ext_modules=[my_module_cpp]) # extension packages
