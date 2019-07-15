#include <cassert>
#include <vector>


#include "transpose.h"


/// Adapter function to transpose a std::vector.
///
/// Uses std::vector to store and manage data.
///
void
Transpose(std::vector<int> const & in,
          unsigned const rows,
          unsigned const columns,
          std::vector<int> & out)
{
  assert(in.size() == rows * columns);
  out.resize(rows * columns);
  Transpose(in.data(), rows, columns, out.data());
}
