#include "GCA_trivector.hpp"
#include "GCA_vector.hpp"
#include "GCA_quadvector.hpp"

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
		double value = (this[0][0]*other[3]) - (this[0][1]*other[2]) + (this[0][2]*other[1]) - (this[0][3]*other[0]);
		GCA_quadvector quadvector;
		return quadvector;
	}
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_trivector& trivector){
        stream << "[";
            stream << " " << trivector.transpose();
        stream << " ]";
        return stream;
    }
}
