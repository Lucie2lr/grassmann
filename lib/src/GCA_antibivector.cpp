#include "GCA_antibivector.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antiscalar.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_bivector.hpp"

namespace gca{
	GCA_antibivector::GCA_antibivector()
		: Eigen::VectorXd(6) {}
	
	GCA_antibivector::GCA_antibivector(const GCA_antibivector& other)
		: Eigen::VectorXd(other) {}

	GCA_antibivector::~GCA_antibivector()
	{}

	GCA_antibivector& GCA_antibivector::operator=(const GCA_antibivector& other){
		this->Eigen::VectorXd::operator=(other);
	}
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_antibivector& bivector){
        stream << "[";
            stream << " " << bivector.transpose();
        stream << "]";
        return stream;
    }

	//Forme Hessienne
	GCA_antivector GCA_antibivector::operator^(const GCA_antitrivector& other) const{
		GCA_antivector trivector;
		trivector[0] = this[0][0]*other[2] - this[0][1]*other[1] + this[0][3]*other[0];
		trivector[1] = this[0][0]*other[3] - this[0][2]*other[1] + this[0][4]*other[0];
		trivector[2] = this[0][1]*other[3] - this[0][2]*other[2] + this[0][5]*other[0];
		trivector[3] = this[0][3]*other[3] - this[0][4]*other[2] + this[0][5]*other[1];
		return trivector;
		
	}

	GCA_antibivector GCA_antibivector::operator^(const GCA_antiquadvector& other) const{
		return other^(*this);
	}

	GCA_antiscalar GCA_antibivector::operator^(const GCA_antibivector& other) const{
		GCA_antiscalar antiscalar((this[0][0]*other[5]) + (this[0][1]*other[4]) - (this[0][2]*other[3]) + (this[0][3]*other[2]) - (this[0][4]*other[1]) + (this[0][5]*other[0]));
		return antiscalar;
	}

	GCA_bivector GCA_antibivector::operator~(){
		GCA_bivector biA;
		biA << this[0][0], this[0][1], this[0][2], this[0][3], this[0][4], this[0][5];
		return biA;
	}
}
