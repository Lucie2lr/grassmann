#include <iostream>

#include "Vector.hpp"

namespace GCA{

	Vector::Vector()
		: Eigen::VectorXd(){
	}
	
	Vector::Vector(int size)
		: Eigen::VectorXd(size){
	}
			
	Vector::~Vector(){}

    //Constructeur par recopie
    Vector& Vector::operator=(const Vector& other) const
    {
        this[0] = other[0];
        this[1] = other[1];
    }

    //On récupère l'air du parallélogramme formé par les deux vecteurs
    /*BiVector& Vector::operator^(const Vector& other) const
    {
    	BiVector res;
    	res = 1/2 * (this[0]*other[1] - this[1]*other[0]);
    	return res;
    }*/
}
