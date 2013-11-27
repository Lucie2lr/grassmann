#include <iostream>

#include "Vector.hpp"
#include "BiVector.hpp"

namespace GCA{

	Vector::Vector()
		: Eigen::VectorXd(){
	}
	
	Vector::Vector(int size)
		: Eigen::VectorXd(size){
	}

    Vector::Vector(double x, double y, double z, double w)
        : Eigen::VectorXd(4){
		this[0] << x, y, z, w;
    }
    
    Vector::Vector(const Eigen::VectorXd& other)
		: Eigen::VectorXd(other){}
			
	Vector::~Vector(){}

    Vector& Vector::operator=(const Vector& other)
    {
        this->Eigen::VectorXd::operator=(other);
    }  
    
    bool Vector::operator==(const Vector& other){
		this->Eigen::VectorXd::operator==(other);
	}
    
    bool Vector::operator!=(const Vector& other){
		this->Eigen::VectorXd::operator!=(other);
	}

    //On récupère l'air du parallélograbool operator==(const Vector& other);mme formé par les deux vecteurs
    /*BiVector Vector::operator^(const Vector& other) const
    {
    	BiVector res;
    	res = 1/2 * (this[0]*other[1] - this[1]*other[0]);
    	return res;
    }*/
}
