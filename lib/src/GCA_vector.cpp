#include <iostream>

#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"

namespace gca{

	GCA_vector::GCA_vector()
		: Eigen::Vector4d(){
	}

    GCA_vector::GCA_vector(const double x,const double y,const double z,const double w)
        : Eigen::Vector4d(x, y, z, w){}
    
    GCA_vector::GCA_vector(const GCA_vector& other)
		: Eigen::Vector4d(other){}
			
	GCA_vector::~GCA_vector(){}

    GCA_vector& GCA_vector::operator=(const GCA_vector& other)
    {
        this->Eigen::Vector4d::operator=(other);
    }  
    
    bool GCA_vector::operator==(const GCA_vector& other) const{
		this->Eigen::Vector4d::operator==(other);
	}
    
    bool GCA_vector::operator!=(const GCA_vector& other) const{
		this->Eigen::Vector4d::operator!=(other);
	}
	
	GCA_vector GCA_vector::operator^(const GCA_scalar& other) const{
		return other^*this;
	}
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_vector& vector){
        stream << "[";
            stream << " " << vector.transpose();
        stream << " ]";
        return stream;
    }

    //Droite de Plücker
    /*GCA_bivector GCA_vector::operator^(const GCA_vector& other) const
    {
    	GCA_bivector res;
    	res = 1/2 * (this[0]*other[1] - this[1]*other[0]);
    	return res;
    }*/
}
