#include "GCA_antitrivector.hpp"

#include "GCA_antiscalar.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_vector.hpp"

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
	
	GCA_antitrivector GCA_antitrivector::operator^(const GCA_antiscalar& other) const{
		return other^*this;
	}

    GCA_antiquadvector GCA_antitrivector::operator^(const GCA_antivector& other) const{
        GCA_antiquadvector antiquadvector((this[0][0]*other[3]) - (this[0][1]*other[2]) + (this[0][2]*other[1]) - (this[0][3]*other[0]));
        return antiquadvector;
    }
	
    GCA_vector GCA_antitrivector::operator~() const{
        GCA_vector A;
        A << -this[0][3], this[0][2], -this[0][1], this[0][0];
        return A;
    }


    //AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_antitrivector& vector){
        stream << "[";
            stream << " " << vector(0) << " |ē123| ";
            stream << " " << vector(1) << " |ē124| ";
            stream << " " << vector(2) << " |ē134| ";
            stream << " " << vector(3) << " |ē234| ";
        stream << " ]";
        return stream;
    }

}
