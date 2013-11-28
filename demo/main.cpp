#include <iostream>

#include "GCA_vector.hpp"

int main()
{
  gca::GCA_vector A(1, 2, 3, 4);
  
  gca::GCA_vector B(1, 3, 4, 5);
  
  std::cout << "A : " << A.transpose() << std::endl;
  std::cout << "B : " << B.transpose() << std::endl;
  
  if(A != B)
	std::cout << "Pinaaaaaaaaaage"<< std::endl;
}
