#include <iostream>

#include "Vector.hpp"

namespace GCA{

	Vector::Vector()
		: Eigen::VectorXd(){
	}
	
	Vector::Vector(int size)
		: Eigen::VectorXd(size){
	}

    Vector::Vector(double e1, double e2, double e3, double e4)
        : Eigen::VectorXd(e1,e2,e3,e4){
    }
			
	Vector::~Vector(){}

    //Constructeur par recopie
    Vector Vector::operator=(const Vector& other) const
    {
        for(int i=0; i<this.size ; ++i){
            this[i] = other[i];
        }
    }

    //On récupère l'air du parallélogramme formé par les deux vecteurs
    /*BiVector Vector::operator^(const Vector& other) const
    {
    	BiVector res;
    	res = 1/2 * (this[0]*other[1] - this[1]*other[0]);
    	return res;
    }*/
}
