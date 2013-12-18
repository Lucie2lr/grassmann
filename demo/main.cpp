#include <iostream>

#include "grassmanCayley.hpp"


void plop (){
    gca :: GCA_vector a (1.0 ,2.0 ,3.0 ,1.0);
    gca :: GCA_vector b ;
    b << 3.0 , 2.0 , 1.0 , 1.0;
    gca :: GCA_bivector l = a ^ b ; // l is a Plucker line
    std :: cout << "\n--------------- Plucker line ---------------" << std :: endl ;
    std :: cout << "l : " << l << std :: endl ;
    gca :: GCA_vector x1 (2.0 , -1.0 , -1.0 ,1.0);
    gca :: GCA_vector x2 (1.0 , -1.0 ,1.0 ,1.0);
    gca :: GCA_vector x3 ( -1.0 , -1.0 , -2.0 ,1.0);
    gca :: GCA_trivector d = x1 ^ x2 ^ x3 ; // d is a plane
    std :: cout << "Plan : " << d << std :: endl ;
    std :: cout << " intersection : " << (~d ^ ~l) << std :: endl ;
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

	// OPERATEUR ~
	std::cout << "Opérateur ~       ~a --> Antiquadvector = " << ~a << std::endl;







	/********** VECTEURS **************/
	std::cout << "\n------------- VECTOR -------------" << std::endl;
	
	gca::GCA_vector A(2.0, 3.0, 4.0, 1.0);
	gca::GCA_vector B;
	
	// OPERATEUR =
	B=A;
	std::cout << "Opérateur =       A = B = " << B << std::endl;
	
	if(A==B){
		std::cout << "                  Test A == B ? TRUE" << std::endl;
	}else{
		std::cout << "                  Test A == B ? FALSE" << std::endl;
	}
	// OPERATEUR <<
	B << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      B << 3.0, 4.0, 5.0, 1.0 = " << B << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ A = " << (a^A) << std::endl;
	std::cout << "Opérateur ^       A ^ a = " << (A^a) << std::endl;

	// OPERATEUR ^ vector
	std::cout << "Opérateur ^       A ^ B = " << (A^B) << std::endl;
	std::cout << "Opérateur ^       B ^ A = " << (B^A) << std::endl;

	// OPERATEUR ~
	std::cout << "Opérateur ~       ~A --> Antitrivector = " << ~A << std::endl;







	/********** BIVECTEURS **************/
	std::cout << "\n------------- BIVECTOR -------------" << std::endl;
	gca::GCA_bivector biA;
	biA << -10.0, -9.0, -4.0, 6.0, 0.0, -1.0;
	gca::GCA_bivector biB;

	gca::GCA_bivector biC(1.,2.,3.,4.,5.,6.);
	std::cout << "biC : " << biC << std::endl; 

	// OPERATEUR =
	biB = biA;
	std::cout << "Opérateur =       biA = biB = " << biB << std::endl;

	// OPERATEUR ==
	if(biA==biB){
		std::cout << "                  Test biA == biB ? TRUE" << std::endl;
	}else{
		std::cout << "                  Test biA == biB ? FALSE" << std::endl;
	}
	biA = a ^ biA;
	if(biA==biB){
		std::cout << "                  Test a ^ biA == biB ? TRUE" << std::endl;
	}else{
		std::cout << "                  Test a ^ biA == biB ? FALSE" << std::endl;
	}
	
	// OPERATEUR <<
	biB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0;
	std::cout << "Opérateur <<      biB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0 = " << biB << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ biA = " << (a^biA) << std::endl;

	// OPERATEUR ^ vecteur
	std::cout << "Opérateur ^       biA ^ A = " << (biA^A) << std::endl;
	std::cout << "Opérateur ^       A ^ biA = " << (A^biA) << std::endl;

	//OPERATEUR ~
	std::cout << "Opérateur ~       ~biA --> antibivector = " << ~biA << std::endl;







	/********** TRIVECTEURS **************/
	std::cout << "\n------------- TRIVECTOR -------------" << std::endl;
	gca::GCA_trivector triA;
	triA << -11.0, -10.0, -3.0, 7.0;
	gca::GCA_trivector triB;
	gca::GCA_trivector triC(1.,2.,3.,4.);

	std::cout << "triC : " << triC << std::endl;

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

	//OPERATEUR ~
	std::cout << "Opérateur ~       ~triA --> antivector = " << ~triA << std::endl;








	/********** QUADVECTEURS **************/
	std::cout << "\n------------- QUADVECTOR -------------" << std::endl;
	gca::GCA_quadvector quadA;
	quadA << -1.0;
	gca::GCA_quadvector quadB;
	gca::GCA_quadvector quadC(1.);

	std::cout << " quadC : " << quadC << std::endl;

	// OPERATEUR =
	quadB = quadA;
	std::cout << "Opérateur =       quadA = quadB = " << quadB << std::endl;
	
	// OPERATEUR <<
	quadB << 5.0;
	std::cout << "Opérateur <<      quadB << 5.0 = " << quadB << std::endl;
	
	// OPERATEUR ^ scalaire
	std::cout << "Opérateur ^       a ^ quadA = " << (a^quadA) << std::endl;
	
	//OPERATEUR ~
	std::cout << "Opérateur ~       ~quadA --> antiscalar = " << ~quadA << std::endl;








	/********** ANTISCALAIRE **************/
	std::cout << "\n------------- ANTISCALAR -------------" << std::endl;
	gca::GCA_antiscalar antia;
	antia << -1.0;
	gca::GCA_antiscalar antib;
	gca::GCA_antiscalar antic(1.);

	std::cout << "antic : " << antic << std::endl;

	// OPERATEUR =
	antib = antia;
	std::cout << "Opérateur =       antia = antib = " << antib << std::endl;
	
	// OPERATEUR <<
	antib << 5.0;
	std::cout << "Opérateur <<      antib << 5.0 = " << antib << std::endl;
	
	//OPERATEUR ~
	std::cout << "Opérateur ~       ~antia --> quadvector = " << ~antia << std::endl;








	/********** ANTIVECTEURS **************/
	std::cout << "\n------------- ANTIVECTOR -------------" << std::endl;
	gca::GCA_antivector antiA;
	antiA << -11.0, -10.0, -3.0, 7.0;
	gca::GCA_antivector antiB;
	gca::GCA_antivector antiC(1.,2.,3.,4.);

	std::cout << "antiC : " << antiC << std::endl;

	// OPERATEUR =
	antiB = antiA;
	std::cout << "Opérateur =       antiA = antiB = " << antiB << std::endl;
	
	// OPERATEUR <<
	antiB << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      antiB << 5.0, 2.0, 5.0, 1.0 = " << antiB << std::endl;

	// OPERATEUR ^ antiscalaire
	std::cout << "Opérateur ^       antia ^ antiA = " << (antia^antiA) << std::endl;
	std::cout << "Opérateur ^       antiA ^ antia = " << (antiA^antia) << std::endl;

	// OPERATEUR ^ antivector
	std::cout << "Opérateur ^       antiA ^ antiB = " << (antiA^antiB) << std::endl;
	std::cout << "Opérateur ^       antiB ^ antiA = " << (antiB^antiA) << std::endl;

	//OPERATEUR ~
	std::cout << "Opérateur ~       ~antiA --> trivector = " << ~antiA << std::endl;







	/********** ANTIBIVECTEURS **************/
	std::cout << "\n------------- ANTIBIVECTOR -------------" << std::endl;
	gca::GCA_antibivector antibiA;
	antibiA << -10.0, -9.0, -4.0, 6.0, 0.0, -1.0;
	gca::GCA_antibivector antibiB;
	gca::GCA_antibivector antibiC(1.,2.,3.,4.,5.,6.);

	std::cout << "antibiC : " << antibiC << std::endl;

	// OPERATEUR =
	antibiB = antibiA;
	std::cout << "Opérateur =       antibiA = antibiB = " << antibiB << std::endl;
	
	// OPERATEUR <<
	antibiB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0;
	std::cout << "Opérateur <<      antibiB << 5.0, 2.0, 5.0, 1.0, 10.0, 3.0 = " << antibiB << std::endl;

	// OPERATEUR ^ antiscalaire
	std::cout << "Opérateur ^       antia ^ antibiA = " << (antia^antibiA) << std::endl;
	std::cout << "Opérateur ^       antibiA ^ antia = " << (antibiA^antia) << std::endl;

	// OPERATEUR ^ antivector
	std::cout << "Opérateur ^       antibiA ^ antiB = " << (antibiA^antiB) << std::endl;
	std::cout << "Opérateur ^       antiB ^ antibiA = " << (antiB^antibiA) << std::endl;

	// OPERATEUR ^ antibivector
	std::cout << "Opérateur ^       antibiA ^ antibiB = " << (antibiA^antibiB) << std::endl;
	std::cout << "Opérateur ^       antibiB ^ antibiA = " << (antibiB^antibiA) << std::endl;

	//OPERATEUR ~
	std::cout << "Opérateur ~       ~antibiA --> bivector = " << ~antibiA << std::endl;







	/********** ANTITRIVECTOR **************/
	std::cout << "\n------------- ANTITRIVECTOR -------------" << std::endl;
	
	gca::GCA_antitrivector antitriA(2.0, 3.0, 4.0, 1.0);
	gca::GCA_antitrivector antitriB;
	gca::GCA_antitrivector antitriC(1.,2.,3.,4.);

	std::cout << "antitriC : " << antitriC << std::endl;
	
	// OPERATEUR =
	antitriB=antitriA;
	std::cout << "Opérateur =       antitriA = antitriB = " << antitriB << std::endl;
	
	// OPERATEUR <<
	antitriB << 5.0, 2.0, 5.0, 1.0;
	std::cout << "Opérateur <<      antitriB << 3.0, 4.0, 5.0, 1.0 = " << antitriB << std::endl;

	// OPERATEUR ^ antiscalaire
	std::cout << "Opérateur ^       antia ^ antitriA = " << (antia^antitriA) << std::endl;
	std::cout << "Opérateur ^       antitriA ^ antia = " << (antitriA^antia) << std::endl;

	// OPERATEUR ^ antivector
	std::cout << "Opérateur ^       antitriA ^ antiB = " << (antibiA^antiB) << std::endl;
	std::cout << "Opérateur ^       antiB ^ antitriA = " << (antiB^antibiA) << std::endl;

	// OPERATEUR ~
	std::cout << "Opérateur ~       ~antitriA --> vector = " << ~antitriA << std::endl;








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
	
	// OPERATEUR ^ antiscalaire
	std::cout << "Opérateur ^       antia ^ antiquadA = " << (antia^antiquadA) << std::endl;
	std::cout << "Opérateur ^       antiquadA ^ antia = " << (antiquadA^antia) << std::endl;
	
	// OPERATEUR ~
	std::cout << "Opérateur ~       ~antiquadA --> scalaire = " << ~antiquadA << std::endl;
	
}

int main()
{
	test();
    plop();
    return EXIT_SUCCESS;
}
