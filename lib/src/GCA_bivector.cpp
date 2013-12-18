#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"
#include "GCA_vector.hpp"
#include "GCA_quadvector.hpp"
#include "GCA_scalar.hpp"
#include "GCA_antibivector.hpp"
#include <iostream>

namespace gca{
	GCA_bivector::GCA_bivector()
		: Eigen::VectorXd(6) {}

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
		GCA_vector u = this->u();
		GCA_vector v = this->v();
		GCA_vector uOther = other.u();
		GCA_vector vOther = other.v();
		double coeff = u[0] / uOther[0];
		double epsilon = 0.000000001;
		for(int i = 0; i < 3; ++i){
			if( ( u[i] -(uOther[i]*coeff) > epsilon ) || ( v[i] -(vOther[i]*coeff) > epsilon ) ) {
				return false;
			}
		}
		return true;
		/*this->Eigen::VectorXd::operator==(other);*/
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

	GCA_antibivector GCA_bivector::operator~(){
		GCA_antibivector antibiA;
		antibiA << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
		return antibiA;
	}


	GCA_vector GCA_bivector::u() const{
		GCA_vector u;
		u << this[0][2], this[0][4], this[0][4], 0;
		return u;
	}

	GCA_vector GCA_bivector::v() const{
		GCA_vector v;
		v << this[0][3], this[0][1], this[0][0], 0;
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
