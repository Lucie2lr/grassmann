#include <iostream>

#include "Vector.hpp"

int main()
{
  GCA::Vector A(1, 2, 3, 4);
  
  GCA::Vector B(1, 3, 4, 5);
  
  std::cout << "A : " << A.transpose() << std::endl;
  std::cout << "B : " << B.transpose() << std::endl;
  
  if(A != B)
	std::cout << "Pinaaaaaaaaaage"<< std::endl;
}
