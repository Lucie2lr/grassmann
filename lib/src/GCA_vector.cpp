#include <iostream>

#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"

namespace gca{

	GCA_vector::GCA_vector()
		: Eigen::VectorXd(){
	}
	
	GCA_vector::GCA_vector(int size)
		: Eigen::VectorXd(size){
	}

    GCA_vector::GCA_vector(double x, double y, double z, double w)
        : Eigen::VectorXd(4){
		this[0] << x, y, z, w;
    }
    
    GCA_vector::GCA_vector(const Eigen::VectorXd& other)
		: Eigen::VectorXd(other){}
			
	GCA_vector::~GCA_vector(){}

    GCA_vector& GCA_vector::operator=(const GCA_vector& other)
    {
        this->Eigen::VectorXd::operator=(other);
    }  
    
    bool GCA_vector::operator==(const GCA_vector& other){
		this->Eigen::VectorXd::operator==(other);
	}
    
    bool GCA_vector::operator!=(const GCA_vector& other){
		this->Eigen::VectorXd::operator!=(other);
	}

    //On récupère l'air du parallélograbool operator==(const GCA_vector& other);mme formé par les deux vecteurs
    /*BiVector GCA_vector::operator^(const GCA_vector& other) const
    {
    	BiVector res;
    	res = 1/2 * (this[0]*other[1] - this[1]*other[0]);
    	return res;
    }*/
}
