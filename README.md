## **OneginSort**
-----------------

Simple program for sorting texts

Libraries with functions and documentation included

## Build
--------
Use ``make`` to build program:
```
$ make
```

If you want to remove temp *.o files after build:
```
$ make clean
```

To generate docs use ``make``:
```
$ make docs
```
or you can use ``doxygen`` (config file included):
```
$ doxygen config
```

If you want to remove docs:
```
$ make removeDocs
```

## Usage
--------
Just type ``./a`` in terminal like this:
```
$ a -i <input-file-name> -o <output-file-name>
$
```

Without -i it will automatically use ``onegin.txt`` (included) as **input file name**.
Without -o it will automatically use ``output.txt`` as **output file name**.

## What's included?
-------------------
- ``main.c`` - source file for program
- ``OneginSort.h`` and ``OneginSort.c`` - a library for text sorting
- ``StringArray.h`` and ``StringArray.c`` - a library for dynamic cstring array
- ``StringFunctions.h`` and ``StringFunctions.c`` - a library for operating with cstrings
