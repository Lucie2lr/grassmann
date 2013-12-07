#include "GCA_vector.hpp"
#include "GCA_scalar.hpp"
#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"
#include "GCA_quadvector.hpp"
#include "GCA_antitrivector.hpp"

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

    GCA_trivector GCA_vector::operator^(const GCA_bivector& other) const{
        GCA_trivector trivector = other^*this;
        for(int i = 0; i<4; ++i){
            trivector[i] = -trivector[i];
        }
        return trivector;
    }

    GCA_quadvector GCA_vector::operator^(const GCA_trivector& other) const{
        GCA_quadvector quadvector = other^*this;
        quadvector.setValue(- quadvector.getValue());
        return quadvector;
    }

    GCA_antitrivector GCA_vector::operator~(void){
        GCA_antitrivector antitriA;
        antitriA << this[0][0], this[0][1], this[0][2], this[0][3];
        return antitriA;
    }


    //AUTRES METHODES	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_vector& vector){
        stream << "[";
            stream << " " << vector.transpose();
        stream << " ]";
        return stream;
    }



}
