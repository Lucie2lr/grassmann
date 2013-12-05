#include <iostream>

#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"
#include "GCA_quadvector.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antibivector.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antiscalar.hpp"


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


	/********** Antiquadvector **************/
	std::cout << "\n------------- ANTIQUADVECTOR -------------" << std::endl;
	
	gca::GCA_antiquadvector antiquadA(2.0);
	gca::GCA_antiquadvector antiquadB;
	
	// OPERATEUR =
	antiquadB=antiquadA;
	std::cout << "Opérateur =       antiquadA = antiquadB = " << antiquadB << std::endl;
	
	// OPERATEUR <<
	antiquadB<<3.0;
	std::cout << "Opérateur <<      antiquadB << 3.0 = " << antiquadB << std::endl;
	
	// OPERATEUR ^ antiquadvecotr
	std::cout << "Opérateur ^       antiquadA ^ antiquadB = " << (antiquadA^antiquadB) << std::endl;
	



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


	/********** ANTITRIVECOTR **************/
	std::cout << "\n------------- ANTITRIVECTOR -------------" << std::endl;
	
	gca::GCA_antitrivector antitriA(2.0, 3.0, 4.0, 1.0);
	gca::GCA_antitrivector antitriB;
	
	// OPERATEUR =
	antitriB=antitriA;
	std::cout << "Opérateur =       antitriA = antitriB = " << antitriB << std::endl;
	
	// OPERATEUR <<
	antitriB << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      antitriB << 3.0, 4.0, 5.0, 1.0 = " << antitriB << std::endl;
	
	// OPERATEUR ^ antiquadvector
	std::cout << "Opérateur ^       antiquadA ^ antitriA = " << (antiquadA^antitriA) << std::endl;
	
	// OPERATEUR ^ antiquadvector
	std::cout << "Opérateur ^       antitriA ^ antiquadA = " << (antitriA^antiquadA) << std::endl;

	// OPERATEUR ^ antitrivector
	std::cout << "Opérateur ^       antitriA ^ antitriB = " << (antitriA^antitriB) << std::endl;
	std::cout << "Opérateur ^       antitriB ^ antitriA = " << (antitriB^antitriA) << std::endl;



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



	/********** ANTIBIVECTEURS **************/
	std::cout << "\n------------- ANTIBIVECTOR -------------" << std::endl;
	gca::GCA_antibivector antibiA;
	biA << -10.0, -9.0, -4.0, 6.0, 0.0, -1.0;
	gca::GCA_antibivector antibiB;

	// OPERATEUR =
	antibiB = antibiA;
	std::cout << "Opérateur =       antibiA = antibiB = " << antibiB << std::endl;
	
	// OPERATEUR <<
	antibiB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0;
	std::cout << "Opérateur <<      antibiB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0 = " << antibiB << std::endl;
	
	// OPERATEUR ^ antiquadvector
	std::cout << "Opérateur ^       antiquadA ^ antibiA = " << (antiquadA^antibiA) << std::endl;

	// OPERATEUR ^ antitrivecteur
	std::cout << "Opérateur ^       antibiA ^ antitriA = " << (antibiA^antitriA) << std::endl;
	std::cout << "Opérateur ^       antitriA ^ antibiA = " << (antitriA^antibiA) << std::endl;




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



	/********** ANTIVECTEURS **************/
	std::cout << "\n------------- ANTIVECTOR -------------" << std::endl;
	gca::GCA_antivector antiA;
	antiA << -11.0, -10.0, -3.0, 7.0;
	gca::GCA_antivector antiB;

	// OPERATEUR =
	antiB = antiA;
	std::cout << "Opérateur =       antiA = antiB = " << antiB << std::endl;
	
	// OPERATEUR <<
	antiB << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      antiB << 5.0, 2.0, 5.0, 1.0 = " << antiB << std::endl;
	
	// OPERATEUR ^ antiquadvector
	std::cout << "Opérateur ^       antiquadA ^ antiA = " << (antiquadA^antiA) << std::endl;

	// OPERATEUR ^ antitrivector
	std::cout << "Opérateur ^       antiA ^ antitriA = " << (antiA^antitriA) << std::endl;
	std::cout << "Opérateur ^       antitriA ^ antiA = " << (antitriA^antiA) << std::endl;




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
	


	/********** ANTISCALAIRE **************/
	std::cout << "\n------------- ANTISCALAR -------------" << std::endl;
	gca::GCA_antiscalar antia;
	antia << -1.0;
	gca::GCA_antiscalar antib;

	// OPERATEUR =
	antib = antia;
	std::cout << "Opérateur =       antia = antib = " << antib << std::endl;
	
	// OPERATEUR <<
	antib << 5.0;
	std::cout << "Opérateur <<      antib << 5.0 = " << antib << std::endl;
	
	// OPERATEUR ^ antiquadvector
	std::cout << "Opérateur ^       antiquadA ^ antia = " << (antiquadA^antia) << std::endl;
	
	
}

int main()
{
	test();
    plop();
    return EXIT_SUCCESS;
}
