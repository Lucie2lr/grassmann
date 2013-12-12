#include "GCA_antivector.hpp"
#include "GCA_antiscalar.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_trivector.hpp"

namespace gca{
	GCA_antivector::GCA_antivector()
		: Eigen::VectorXd(4) {}
	
	GCA_antivector::GCA_antivector(const GCA_antivector& other)
		: Eigen::VectorXd(other) {}

	GCA_antivector::~GCA_antivector()
	{}

	GCA_antivector& GCA_antivector::operator=(const GCA_antivector& other){
		this->Eigen::VectorXd::operator=(other);
	}

	GCA_antiscalar GCA_antivector::operator^(const GCA_antitrivector& other) const{
		GCA_antiscalar antiscalar((this[0][0]*other[3]) - (this[0][1]*other[2]) + (this[0][2]*other[1]) - (this[0][3]*other[0]));
		return antiscalar;
	}

	GCA_trivector GCA_antivector::operator~(void){
		GCA_trivector triA;
		triA << this[0][0], this[0][1], this[0][2], this[0][3];
		return triA;
	}

	//AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_antivector& antivector){
        stream << "[";
            stream << " " << antivector.transpose();
        stream << " ]";
        return stream;
    }
}
