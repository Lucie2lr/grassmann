#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"
#include "GCA_vector.hpp"
#include "GCA_quadvector.hpp"
#include "GCA_scalar.hpp"
#include "GCA_antibivector.hpp"

namespace gca{
	GCA_bivector::GCA_bivector()
		: Eigen::VectorXd(6) {}

	/*GCA_bivector::GCA_bivector(const double xy,const double xz,const double xw,const double yz,const double yw,const double zw)
		: Eigen::VectorXd(xy, xz, xw, yz, yw, zw) {}
	*/
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

	GCA_antibivector GCA_bivector::operator~(){
		GCA_antibivector antibiA;
		antibiA << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
		return antibiA;
	}

	//AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_bivector& bivector){
        stream << "[";
            stream << " " << bivector.transpose();
        stream << "]";
        return stream;
    }

}
