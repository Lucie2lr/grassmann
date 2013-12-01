#include <iostream>

#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"

int main()
{
  gca::GCA_vector A;
  A << 1, 2, 3, 4;
  gca::GCA_vector B(1, 4, 3, 5);
  
  std::cout << "A : " << A << std::endl;
  std::cout << "B : " << B << std::endl;
  
  gca::GCA_scalar a;
  a << 2;
  gca::GCA_scalar b(3);
  
  /*std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  gca::GCA_vector C = A^a;
  std::cout << "A^a : " << C << std::endl;
*/
  
  gca::GCA_bivector C;
  C = A^B;;

  std::cout << "A^B : " << C << std::endl;

}
