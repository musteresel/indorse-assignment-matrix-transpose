/// \file
///
/// Implementation of the matrix transposition algorithm.
///


#include <cassert>


#include "transpose.h"


/// Transpose function operating on raw memory.
///
/// This functions transposes the elements of a matrix, supplied as an
/// array in row-major order, and writes them into the supplied out
/// array.  The out array must have sufficient size to hold all
/// elements.
///
/// \param in Input matrix, as an array of size rows * columns.
///
/// \param rows Number of rows of the input matrix.
///
/// \param columns Number of columns of the input matrix.
///
/// \param out Array to store the output matrix, also in row-major
/// order.  Size must be at least rows * columns.
///
void
Transpose(int const * const in,
          unsigned const rows,
          unsigned const columns,
          int * const out)
{
  assert(in != nullptr);
  assert(out != nullptr);
  assert(rows > 0);
  assert(columns > 0);
  for (unsigned row = 0; row < rows; ++row)
    {
      for (unsigned column = 0; column < columns; ++column)
        {
          out[column * rows + row] = in[row * columns + column];
        }
    }
}
