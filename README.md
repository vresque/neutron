# NEUTRON

Neutron is a self-compiling language with a python-like syntax.
It is trying to achieve the following 3 Principals:

- Fast
- Easy
- Friendly

Most of the work is currently being put into the c-based bootstrap-compiler (The compiler that will compile the actual compiler)

# FILE TYPES

### .NTN FILES

These are the main neutron files that you will write your source code in.

### .NCIN FILES

These are so-called "neutron compiler instructions" files. They are basically the same as .ntn files, but they are **only** used in files concerning the compiler.
They exist for me to be able to differenciate source files that belong to tests, built-in functions etc. and files that belong to the compiler.
