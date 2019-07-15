#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


#include "transpose.h"


void
PrintMatrix(std::vector<int> const & matrix,
            unsigned const rows,
            unsigned const columns)
{
  auto iterator = std::begin(matrix);
  do
    {
      std::copy_n(iterator,
                  columns - 1,
                  std::ostream_iterator<int>(std::cout, " "));
      std::advance(iterator, columns - 1);
      std::cout << *iterator;
      ++iterator;
      if (iterator == std::end(matrix))
        {
          break;
        }
      std::cout << "\n";
    }
  while (true);
}


int
main()
{
  std::cout << "Rows? Columns? (separated by whitespace)"
            << std::endl;
  unsigned rows, columns;
  if (! (std::cin >> rows >> columns))
    {
      std::cerr << "IO Error, could not get rows/columns"
                << std::endl;
      return EXIT_FAILURE;
    }
  std::vector<int> matrix;
  matrix.resize(rows * columns);
  std::cout << "Values? (separated by whitespace)" << std::endl;
  for (unsigned i = 0; i < matrix.size(); ++i)
    {
      if (! (std::cin >> matrix[i]))
        {
          std::cerr << "IO Error, could not get matrix (element #"
                    << i << ")" << std::endl;
          return EXIT_FAILURE;
        }
    }
  std::vector<int> result;
  Transpose(matrix, rows, columns, result);
  std::cout << "Input:\n";
  PrintMatrix(matrix, rows, columns);
  std::cout << "\nOutput:\n";
  PrintMatrix(result, columns, rows);
  std::cout << std::endl;
}
