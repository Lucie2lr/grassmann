#include "GCA_antivector.hpp"

#include "GCA_antiscalar.hpp"
#include "GCA_antibivector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_trivector.hpp"

namespace gca{
	GCA_antivector::GCA_antivector()
		: Eigen::VectorXd(4) {}

	GCA_antivector::GCA_antivector(const double xyw, const double xyz, const double xwz, const double ywz)
		: Eigen::VectorXd(4) {
		this[0][0] = xyw;
		this[0][1] = xyz;
		this[0][2] = xwz;
		this[0][3] = ywz;
	}
	
	GCA_antivector::GCA_antivector(const GCA_antivector& other)
		: Eigen::VectorXd(other) {}

	GCA_antivector::~GCA_antivector()
	{}

	GCA_antivector& GCA_antivector::operator=(const GCA_antivector& other){
		this->Eigen::VectorXd::operator=(other);
	}
    
    bool GCA_antivector::operator==(const GCA_antivector& other) const{
		this->Eigen::VectorXd::operator==(other);
	}
    
    bool GCA_antivector::operator!=(const GCA_antivector& other) const{
		this->Eigen::VectorXd::operator!=(other);
	}

	
	GCA_antivector GCA_antivector::operator^(const GCA_antiscalar& other) const{
		return other^(*this);
	}

	GCA_antibivector GCA_antivector::operator^(const GCA_antivector& other) const{
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

	GCA_antitrivector GCA_antivector::operator^(const GCA_antibivector& other) const{
		GCA_antitrivector antitrivector = other^(*this);
        for(int i = 0; i<4; ++i){
            antitrivector[i] = -antitrivector[i];
        }
        return antitrivector;
	}

	GCA_antiquadvector GCA_antivector::operator^(const GCA_antitrivector& other) const{
		GCA_antiquadvector antiquadvector = other^*this;
        antiquadvector.setValue(- antiquadvector.getValue());
        return antiquadvector;
	}

	GCA_trivector GCA_antivector::operator~(){
		GCA_trivector triA;
		triA << -this[0][3], this[0][2], -this[0][1], this[0][0];
		return triA;
	}

	//AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_antivector& antivector){
        stream << "[";
            stream << " " << antivector(0) << " |ē1| ";
            stream << " " << antivector(1) << " |ē2| ";
            stream << " " << antivector(2) << " |ē3| ";
            stream << " " << antivector(3) << " |ē4| ";
        stream << " ]";
        return stream;
    }
}
