#include <iostream>

#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"
#include "GCA_quadvector.hpp"


void plop (){
    gca :: GCA_vector a (1.0 ,2.0 ,3.0 ,1.0);
    gca :: GCA_vector b ;
    b << 3.0 , 2.0 , 1.0 , 1.0;
    gca :: GCA_bivector l = a ^ b ; // l is a Plucker line
    std :: cout << " l : " << l << std :: endl ;
    gca :: GCA_vector x1 (2.0 , -1.0 , -1.0 ,1.0);
    gca :: GCA_vector x2 (1.0 , -1.0 ,1.0 ,1.0);
    gca :: GCA_vector x3 ( -1.0 , -1.0 , -2.0 ,1.0);
    //gca :: GCA_trivector d = x1 ^ x2 ^ x3 ; // d is a plane
    //std :: cout << " intersection : " << ~ d ^~ l << std :: endl ;
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
	std::cout << "\n------------- VECTOR -------------" << std::endl;
	
	gca::GCA_vector A(2.0, 3.0, 4.0, 1.0);
	gca::GCA_vector B;
	
	// OPERATEUR =
	B=A;
	std::cout << "Opérateur =       A = B = " << B << std::endl;
	
	// OPERATEUR <<
	B << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      B << 3.0, 4.0, 5.0, 1.0 = " << B << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ A = " << (a^A) << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       A ^ a = " << (A^a) << std::endl;

	// OPERATEUR ^ vector
	std::cout << "Opérateur ^       A ^ B = " << (A^B) << std::endl;
	std::cout << "Opérateur ^       B ^ A = " << (B^A) << std::endl;



	/********** BIVECTEURS **************/
	std::cout << "\n------------- BIVECTOR -------------" << std::endl;
	gca::GCA_bivector biA;
	biA << -10.0, -9.0, -4.0, 6.0, 0.0, -1.0;
	gca::GCA_bivector biB;

	// OPERATEUR =
	biB = biA;
	std::cout << "Opérateur =       biA = biB = " << biB << std::endl;
	
	// OPERATEUR <<
	biB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0;
	std::cout << "Opérateur <<      biB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0 = " << biB << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ biA = " << (a^biA) << std::endl;

	// OPERATEUR ^ vecteur
	std::cout << "Opérateur ^       biA ^ A = " << (biA^A) << std::endl;
	std::cout << "Opérateur ^       A ^ biA = " << (A^biA) << std::endl;


	/********** TRIVECTEURS **************/
	std::cout << "\n------------- TRIVECTOR -------------" << std::endl;
	gca::GCA_trivector triA;
	triA << -11.0, -10.0, -3.0, 7.0;
	gca::GCA_trivector triB;

	// OPERATEUR =
	triB = triA;
	std::cout << "Opérateur =       triA = triB = " << triB << std::endl;
	
	// OPERATEUR <<
	triB << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      triB << 5.0, 2.0, 5.0, 1.0 = " << triB << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ triA = " << (a^triA) << std::endl;

	// OPERATEUR ^ vecteur
	std::cout << "Opérateur ^       triA ^ A = " << (triA^A) << std::endl;
	std::cout << "Opérateur ^       A ^ triA = " << (A^triA) << std::endl;



	/********** QUADVECTEURS **************/
	std::cout << "\n------------- QUADVECTOR -------------" << std::endl;
	gca::GCA_quadvector quadA;
	quadA << -1.0;
	gca::GCA_quadvector quadB;

	// OPERATEUR =
	quadB = quadA;
	std::cout << "Opérateur =       quadA = quadB = " << quadB << std::endl;
	
	// OPERATEUR <<
	quadB << 5.0;
	std::cout << "Opérateur <<      quadB << 5.0 = " << quadB << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ quadA = " << (a^quadA) << std::endl;
	
	
}

int main()
{
	test();
    plop();
    return EXIT_SUCCESS;
}
