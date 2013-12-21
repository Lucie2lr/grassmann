#include "grassmanCayley.hpp"


namespace gca{
	GCA_trivector::GCA_trivector()
		: Eigen::VectorXd(4) {}

	GCA_trivector::GCA_trivector(const GCA_vector p1, const GCA_vector p2, const GCA_vector p3)
		: Eigen::VectorXd(p1^p2^p3) {}

	GCA_trivector::GCA_trivector(const double xyw, const double xyz, const double xwz, const double ywz)
		: Eigen::VectorXd(4) {
		this[0][0] = xyw;
		this[0][1] = xyz;
		this[0][2] = xwz;
		this[0][3] = ywz;
	}
	
	GCA_trivector::GCA_trivector(const GCA_trivector& other)
		: Eigen::VectorXd(other) {}

	GCA_trivector::~GCA_trivector()
	{}

	GCA_trivector& GCA_trivector::operator=(const GCA_trivector& other){
		this->Eigen::VectorXd::operator=(other);
	}
    
    bool GCA_trivector::operator==(const GCA_trivector& other) const{
		this->Eigen::VectorXd::operator==(other);
	}
    
    bool GCA_trivector::operator!=(const GCA_trivector& other) const{
		this->Eigen::VectorXd::operator!=(other);
	}

	GCA_quadvector GCA_trivector::operator^(const GCA_vector& other) const{
		GCA_quadvector quadvector((this[0][0]*other[3]) - (this[0][1]*other[2]) + (this[0][2]*other[1]) - (this[0][3]*other[0]));
		return quadvector;
	}

	GCA_antiquadvector GCA_trivector::operator|(const GCA_vector& other) const{
		GCA_antiquadvector antiquadvector = ~other^~(*this);
        antiquadvector.setValue(- antiquadvector.getValue());
        return antiquadvector;
	}

	GCA_antitrivector GCA_trivector::operator|(const GCA_bivector& other) const{
		GCA_antitrivector antitrivector = ~other^~(*this);
        for(int i = 0; i<4; ++i){
            antitrivector[i] = -antitrivector[i];
        }
        return antitrivector;
	}


	GCA_antibivector GCA_trivector::operator|(const GCA_trivector& other) const{
		GCA_antibivector res;
		GCA_antivector antiA = ~(*this);
		GCA_antivector antiB = ~other;
        unsigned int k=0;

        for(unsigned int i = 0; i < 3; ++i){
            for(unsigned int j = i+1; j < 4; ++j){
				res[k] = (antiA[i]*antiB[j]) - (antiB[i]*antiA[j]);
				++k;
			}
        }
    	return res;
	}


	GCA_antivector GCA_trivector::operator|(const GCA_quadvector& other) const{
		return ~other^~(*this);
	}

	GCA_antivector GCA_trivector::operator~() const{
		GCA_antivector antiA;
		antiA << -this[0][3], this[0][2], -this[0][1], this[0][0];
		return antiA;
	}

	double GCA_trivector::e123() const{ return this[0][0]; }
    double GCA_trivector::e124() const{ return this[0][1]; }
    double GCA_trivector::e134() const{ return this[0][2]; }
    double GCA_trivector::e234() const{ return this[0][3]; }


	//AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_trivector& trivector){
        stream << "[";
            stream << " " << trivector.transpose();
        stream << " ]";
        return stream;
    }
}
