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

    /*int GCA_vector::size(){
        return this->Eigen::Vector4d::size(); 
    }*/

    //Droite de Plücker
    GCA_bivector GCA_vector::operator^(const GCA_vector& other) const
    {
    	GCA_bivector res;
        unsigned int k=0;
        for(unsigned int i = 0; i < 3; ++i){
            for(unsigned int j = i+1; j < 4; ++j){
				res[k] = (this[0][i]*other[j]) - (other[i]*this[0][j]);
				++k;
			}
        }
    	return res;
    }
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_vector& vector){
        stream << "[";
            stream << " " << vector.transpose();
        stream << " ]";
        return stream;
    }
}
