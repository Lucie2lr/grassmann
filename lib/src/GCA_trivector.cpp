#include "GCA_trivector.hpp"
#include "GCA_quadvector.hpp"
#include "GCA_vector.hpp"
#include "GCA_antivector.hpp"

namespace gca{
	GCA_trivector::GCA_trivector()
		: Eigen::VectorXd(4) {}
	
	GCA_trivector::GCA_trivector(const GCA_trivector& other)
		: Eigen::VectorXd(other) {}

	GCA_trivector::~GCA_trivector()
	{}

	GCA_trivector& GCA_trivector::operator=(const GCA_trivector& other){
		this->Eigen::VectorXd::operator=(other);
	}

	GCA_quadvector GCA_trivector::operator^(const GCA_vector& other) const{
		GCA_quadvector quadvector((this[0][0]*other[3]) - (this[0][1]*other[2]) + (this[0][2]*other[1]) - (this[0][3]*other[0]));
		return quadvector;
	}

	GCA_antivector GCA_trivector::operator~(void){
		GCA_antivector antiA;
		antiA << this[0][0], this[0][1], this[0][2], this[0][3];
		return antiA;
	}


	//AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_trivector& trivector){
        stream << "[";
            stream << " " << trivector.transpose();
        stream << " ]";
        return stream;
    }
}
