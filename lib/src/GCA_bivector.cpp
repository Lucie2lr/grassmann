#include "GCA_bivector.hpp"

namespace gca{
	GCA_bivector::GCA_bivector()
		: Eigen::VectorXd(6) {}
	
	GCA_bivector::GCA_bivector(GCA_bivector& other)
		: Eigen::VectorXd(other) {}

	GCA_bivector::~GCA_bivector()
	{}

	GCA_bivector& GCA_bivector::operator=(const GCA_bivector& other){
		this->Eigen::VectorXd::operator=(other);
	}
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_bivector& bivector){
        stream << "[";
            stream << " " << bivector.transpose();
        stream << " ]";
        return stream;
    }

	//Forme Hessienne
	/*GCA_trivector operator^(const GCA_bivector& other) const{

	}*/
}
