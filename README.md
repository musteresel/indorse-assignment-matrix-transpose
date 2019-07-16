# Transpose a matrix - Indorse.io assignment

This repository contains code for the Indorse.io assignment about
matrix transposition.

## Requirements

 - Get size of matrix as an input from the user.
 - Size should be less than 8 in each direction (rows, columns).
 - Get values to fill the matrix from the user.
 - Transpose matrix.
 - Print original matrix.
 - Print transposed matrix.

## Build / Run tests

To build a simple `make` in the toplevel directory creates a
`transpose` executable.  `make test` creates the `transpose-silent`
executable used for testing (it doesn't print messages to the user)
and runs the tests under `test/` with it.

This assumes a standard Unix build environment, so may not work on
Windows.

To compile manually all you need to do is compile all the `src/*.cc`
files together into a single executable.

There are no dependencies other than the C++ standard library.
Written against C++11.


