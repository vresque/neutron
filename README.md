# NEUTRON

Neutron is a self-compiling language with a python-like syntax.
It is trying to achieve the following 3 Principals:

- Fast
- Easy
- Friendly

Most of the work is currently being put into the c-based bootstrap-compiler (The compiler that will compile the actual compiler)

## FILE TYPES

### .NTN FILES

These are the main neutron files that you will write your source code in.

### .NCIN FILES

These are so-called "neutron compiler instructions" files. They are basically the same as .ntn files, but they are **only** used in files concerning the compiler.
They exist for me to be able to differenciate source files that belong to tests, built-in functions etc. and files that belong to the compiler.

## HELLO WORLD

This currently only compiles using the bootstrapper and is **not** final, many of the elements mentioned **will** be **removed** as soon as I am finished
with the main part of my bootstrapper. The only reason why it is currently like this is because of simplicity for me.

~~~
comp main = (argc: int, argv: Array<String>): int -> {
    print("Hello World");
    return 0;
}
~~~

So, now lets break down this block of code. It is mentioned if a part is being removed on the description of it :).

'comp': This is the keyword for **any** function in Neutron, no matter what it returns. It is short for 'component'. It will not be removed,

'main': This is the name of the function.
'argc, argc': These are input parameters of the main function.

': type': In Neutron, variable types can be declared after the variable is created. You can do this using a colon and a variable type after it. Using this we promised the function that it will get an integer and nothing else. Since we do not want that this function gets mad at us which would lead the compiler to be mad at us, we have to keep our promise. These declarations will be optional in the final version of neutron.

'->': This is reffered to as a 'Pointy'. It is being used to show that a function body is following.

'{}': These are there to show where a function ends and where it starts. These may be removed later.

'print("Hello World")': This is calling the function 'print', it takes in a string, in our case this string is "Hello World".s

';': A semicolon, it is used to tell the compiler that a line ends. This will be removed in final neutron.

'return 0': If you remember, we promised main an integer using: ()**: int**. A return 0 statement will give the main the number 0.

## GETTERS

Getters are very important in any object-oriented language which is why we are going to present you getters in this readme.
~~~
comp main = (argc: int, argv: Array<String>): int -> return 0;
~~~
As you can see, it does not need any braces at all.



