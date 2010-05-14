from distutils.core import setup, Extension

module1 = Extension('sieve',
                    sources = ['sievemodule.c', 'libsieve.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a sieve package',
       ext_modules = [module1])
