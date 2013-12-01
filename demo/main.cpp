#include <iostream>

#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"


void plop (){
    gca :: GCA_vector a (1.0 ,2.0 ,3.0 ,1.0);
    gca :: GCA_vector b ;
    b << 3.0 , 2.0 , 1.0 , 1.0;
    gca :: GCA_bivector l = a ^ b ; // l is a Plucker line
    std :: cout << " l : " << l << std :: endl ;
    gca :: GCA_vector x1 (2.0 , -1.0 , -1.0 ,1.0);
    gca :: GCA_vector x2 (1.0 , -1.0 ,1.0 ,1.0);
    gca :: GCA_vector x3 ( -1.0 , -1.0 , -2.0 ,1.0);
   /* gca :: GCA_trivector d = x1 ^ x2 ^ x3 ; // d is a plane
    std :: cout << " intersection : " << ~ d ^~ l << std :: endl ;*/
}

void test(){
	/********** SCALAIRES **************/
	std::cout << "------------- SCALAIRES -------------" << std::endl;
	
	gca::GCA_scalar a(2.0);
	gca::GCA_scalar b;
	
	// OPERATEUR =
	b=a;
	std::cout << "Opérateur =       a = b = " << b << std::endl;
	
	// OPERATEUR <<
	b<<3.0;
	std::cout << "Opérateur <<      b << 3.0 = " << b << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ b = " << (a^b) << std::endl;
	
	/********** VECTEURS **************/
	std::cout << "\n------------- SCALAIRES -------------" << std::endl;
	
	gca::GCA_vector A(2.0, 3.0, 4.0, 1.0);
	gca::GCA_vector B;
	
	// OPERATEUR =
	B=A;
	std::cout << "Opérateur =       A = B = " << B << std::endl;
	
	// OPERATEUR <<
	B << 3.0, 4.0, 5.0, 1.0;
	std::cout << "Opérateur <<      B << 3.0, 4.0, 5.0, 1.0 = " << B << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ A = " << (a^A) << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       A ^ a = " << (A^a) << std::endl;
	
}

int main()
{
	test();
    plop();
    return EXIT_SUCCESS;
}
