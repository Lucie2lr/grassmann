#include <iostream>

#include "Vector.hpp"

int main()
{
  GCA::Vector A(2);
  A << 1, 2;
  std::cout << A.transpose() << std::endl;
  std::cout << "Hello World !"<< std::endl;
}
