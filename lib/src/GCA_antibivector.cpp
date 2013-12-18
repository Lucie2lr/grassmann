#include "GCA_antibivector.hpp"

#include "GCA_antiscalar.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_bivector.hpp"

namespace gca{
	GCA_antibivector::GCA_antibivector()
		: Eigen::VectorXd(6) {}

	GCA_antibivector::GCA_antibivector(const double xy,const double xz,const double xw,const double yz,const double yw,const double zw)
		: Eigen::VectorXd(6) {
		this[0][0] = xy;
		this[0][1] = xz;
		this[0][2] = xw;
		this[0][3] = yz;
		this[0][4] = yw;
		this[0][5] = zw;
	}
	
	GCA_antibivector::GCA_antibivector(const GCA_antibivector& other)
		: Eigen::VectorXd(other) {}

	GCA_antibivector::~GCA_antibivector()
	{}

	GCA_antibivector& GCA_antibivector::operator=(const GCA_antibivector& other){
		this->Eigen::VectorXd::operator=(other);
	}
    
    bool GCA_antibivector::operator==(const GCA_antibivector& other) const{
		this->Eigen::VectorXd::operator==(other);
	}
    
    bool GCA_antibivector::operator!=(const GCA_antibivector& other) const{
		this->Eigen::VectorXd::operator!=(other);
	}

	GCA_antibivector GCA_antibivector::operator^(const GCA_antiscalar& other) const{
		return GCA_antibivector(other^*this);
	}

	GCA_antitrivector GCA_antibivector::operator^(const GCA_antivector& other) const{
		GCA_antitrivector antitrivector;
		antitrivector[0] = this[0][0]*other[2] - this[0][1]*other[1] + this[0][3]*other[0];
		antitrivector[1] = this[0][0]*other[3] - this[0][2]*other[1] + this[0][4]*other[0];
		antitrivector[2] = this[0][1]*other[3] - this[0][2]*other[2] + this[0][5]*other[0];
		antitrivector[3] = this[0][3]*other[3] - this[0][4]*other[2] + this[0][5]*other[1];
		return antitrivector;
	}

	GCA_antiquadvector GCA_antibivector::operator^(const GCA_antibivector& other) const{
		GCA_antiquadvector antiquadvector((this[0][0]*other[5]) + (this[0][1]*other[4]) - (this[0][2]*other[3]) + (this[0][3]*other[2]) - (this[0][4]*other[1]) + (this[0][5]*other[0]));
		return antiquadvector;
	}

	GCA_bivector GCA_antibivector::operator~(){
		GCA_bivector biA;
		biA << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
		return biA;
	}
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_antibivector& bivector){
        stream << "[";
            stream << " " << bivector(0) << " |ē12| ";
            stream << " " << bivector(0) << " |ē13| ";
            stream << " " << bivector(0) << " |ē14| ";
            stream << " " << bivector(0) << " |ē23| ";
            stream << " " << bivector(0) << " |ē24| ";
            stream << " " << bivector(0) << " |ē34| ";
        stream << "]";
        return stream;
    }
}
