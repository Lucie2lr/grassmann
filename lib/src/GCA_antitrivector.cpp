#include "GCA_antitrivector.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_antibivector.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antiscalar.hpp"

namespace gca{

	GCA_antitrivector::GCA_antitrivector()
		: Eigen::Vector4d(){
	}

    GCA_antitrivector::GCA_antitrivector(const double x,const double y,const double z,const double w)
        : Eigen::Vector4d(x, y, z, w){}
    
    GCA_antitrivector::GCA_antitrivector(const GCA_antitrivector& other)
		: Eigen::Vector4d(other){}
			
	GCA_antitrivector::~GCA_antitrivector(){}

    GCA_antitrivector& GCA_antitrivector::operator=(const GCA_antitrivector& other)
    {
        this->Eigen::Vector4d::operator=(other);
    }  
    
    bool GCA_antitrivector::operator==(const GCA_antitrivector& other) const{
		this->Eigen::Vector4d::operator==(other);
	}
    
    bool GCA_antitrivector::operator!=(const GCA_antitrivector& other) const{
		this->Eigen::Vector4d::operator!=(other);
	}
	
	GCA_antitrivector GCA_antitrivector::operator^(const GCA_antiquadvector& other) const{
		return other^*this;
	}

    //Droite de Plücker
    GCA_antibivector GCA_antitrivector::operator^(const GCA_antitrivector& other) const
    {
    	GCA_antibivector res;
        unsigned int k=0;

        for(unsigned int i = 0; i < 3; ++i){
            for(unsigned int j = i+1; j < 4; ++j){
				res[k] = (this[0][i]*other[j]) - (other[i]*this[0][j]);
				++k;
			}
        }
    	return res;
    }

    GCA_antivector GCA_antitrivector::operator^(const GCA_antibivector& other) const{
        GCA_antivector antivector = other^*this;
        for(int i = 0; i<4; ++i){
            antivector[i] = -antivector[i];
        }
        return antivector;
    }

    GCA_antiscalar GCA_antitrivector::operator^(const GCA_antivector& other) const{
        GCA_antiscalar antiscalar = other^*this;
        antiscalar.setValue(- antiscalar.getValue());
        return antiscalar;
    }
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_antitrivector& vector){
        stream << "[";
            stream << " " << vector.transpose();
        stream << " ]";
        return stream;
    }


    /*int GCA_antitrivector::size(){
        return this->Eigen::Vector4d::size(); 
    }*/
}
