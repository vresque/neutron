# FILE STRUCTURE

### BOOTSTRAP

The c-compiler responsible for bootstrapping the self-hosted compiler.

### COMPILER

The self-hosted compiler (does not exist yet)

# FILE TYPES

### .NTN FILES

These are the main neutron files that you will write your source code in.

### .NCIN FILES

These are so-called "neutron compiler instructions" files. They are basically the same as .ntn files, but they are **only** used in files concerning the compiler.
They exist for me to be able to differenciate source files that belong to tests, built-in functions etc. and files that belong to the compiler.
