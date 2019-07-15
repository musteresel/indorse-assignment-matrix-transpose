#ifndef TRANSPOSE_H
#define TRANSPOSE_H 1


#include <vector>


void
Transpose(int const * const in,
          unsigned const rows,
          unsigned const columns,
          int * const out);


void
Transpose(std::vector<int> const & in,
          unsigned const rows,
          unsigned const columns,
          std::vector<int> & out);


#endif // TRANSPOSE_H
