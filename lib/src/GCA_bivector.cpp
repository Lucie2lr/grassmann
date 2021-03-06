#include "grassmanCayley.hpp"
#include <iostream>

namespace gca{
	GCA_bivector::GCA_bivector()
		: Eigen::VectorXd(6) {}

	GCA_bivector::GCA_bivector(const GCA_vector p1, const GCA_vector p2)
		: Eigen::VectorXd(p1^p2) {}

	GCA_bivector::GCA_bivector(const double xy,const double xz,const double xw,const double yz,const double yw,const double zw)
		: Eigen::VectorXd(6) {
		this[0][0] = xy;
		this[0][1] = xz;
		this[0][2] = xw;
		this[0][3] = yz;
		this[0][4] = yw;
		this[0][5] = zw;
	}
	
	GCA_bivector::GCA_bivector(const GCA_bivector& other)
		: Eigen::VectorXd(other) {}

	GCA_bivector::~GCA_bivector()
	{}

	GCA_bivector& GCA_bivector::operator=(const GCA_bivector& other){
		this->Eigen::VectorXd::operator=(other);
	} 
    
    bool GCA_bivector::operator==(const GCA_bivector& other) const{
		this->Eigen::VectorXd::operator==(other);
	}
    
    bool GCA_bivector::operator!=(const GCA_bivector& other) const{
		this->Eigen::VectorXd::operator!=(other);
	}
	
	//Forme Hessienne
	GCA_trivector GCA_bivector::operator^(const GCA_vector& other) const{
		GCA_trivector trivector;
		trivector[0] = this[0][0]*other[2] - this[0][1]*other[1] + this[0][3]*other[0];
		trivector[1] = this[0][0]*other[3] - this[0][2]*other[1] + this[0][4]*other[0];
		trivector[2] = this[0][1]*other[3] - this[0][2]*other[2] + this[0][5]*other[0];
		trivector[3] = this[0][3]*other[3] - this[0][4]*other[2] + this[0][5]*other[1];
		return trivector;
		
	}

	GCA_bivector GCA_bivector::operator^(const GCA_scalar& other) const{
		return other^(*this);
	}


	GCA_quadvector GCA_bivector::operator^(const GCA_bivector& other) const{
		GCA_quadvector quadvector((this[0][0]*other[5]) + (this[0][1]*other[4]) - (this[0][2]*other[3]) + (this[0][3]*other[2]) - (this[0][4]*other[1]) + (this[0][5]*other[0]));
		return quadvector;
	}

	GCA_antibivector GCA_bivector::operator|(const GCA_quadvector& other) const{
		return GCA_antibivector(~other^~(*this));
	}

	GCA_antitrivector GCA_bivector::operator|(const GCA_trivector& other) const{
		GCA_antibivector antibi = ~(*this);
		GCA_antivector antivec = ~other;
		GCA_antitrivector antitrivector;
		antitrivector[0] = antibi[0]*antivec[2] - antibi[1]*antivec[1] + antibi[3]*antivec[0];
		antitrivector[1] = antibi[0]*antivec[3] - antibi[2]*antivec[1] + antibi[4]*antivec[0];
		antitrivector[2] = antibi[1]*antivec[3] - antibi[2]*antivec[2] + antibi[5]*antivec[0];
		antitrivector[3] = antibi[3]*antivec[3] - antibi[4]*antivec[2] + antibi[5]*antivec[1];
		return antitrivector;
	}

	GCA_antiquadvector GCA_bivector::operator|(const GCA_bivector& other) const{
		GCA_antibivector antibiA = ~(*this);
		GCA_antibivector antibiB = ~other;
		GCA_antiquadvector antiquadvector((antibiA[0]*antibiB[5]) + (antibiA[1]*antibiB[4]) - (antibiA[2]*antibiB[3]) + (antibiA[3]*antibiB[2]) - (antibiA[4]*antibiB[1]) + (antibiA[5]*antibiB[0]));
		return antiquadvector;
	}

	GCA_antibivector GCA_bivector::operator~() const{
		GCA_antibivector antibiA;
		antibiA << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
		return antibiA;
	}

	GCA_vector GCA_bivector::u() const{
		GCA_vector u;
		u << this[0][2], this[0][4], this[0][5], 0;
		return u;
	}

	GCA_vector GCA_bivector::v() const{
		GCA_vector v;
		v << -(this[0][3]), this[0][1], -(this[0][0]), 0;
		return v;
	}

	double GCA_bivector::e12() const{ return this[0][0]; }
	double GCA_bivector::e13() const{ return this[0][1]; }
	double GCA_bivector::e14() const{ return this[0][2]; }
	double GCA_bivector::e23() const{ return this[0][3]; }
	double GCA_bivector::e24() const{ return this[0][4]; }
	double GCA_bivector::e34() const{ return this[0][5]; }

	//AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_bivector& bivector){
        stream << "[";
            stream << " " << bivector.transpose();
        stream << "]";
        return stream;
    }

}
