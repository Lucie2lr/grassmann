#include "GCA_trivector.hpp"

namespace gca{
	GCA_trivector::GCA_trivector()
		: Eigen::VectorXd(4) {}
	
	GCA_trivector::GCA_trivector(GCA_trivector& other)
		: Eigen::VectorXd(other) {}

	GCA_trivector::~GCA_trivector()
	{}

	GCA_trivector& GCA_trivector::operator=(const GCA_trivector& other){
		this->Eigen::VectorXd::operator=(other);
	}
	
	std::ostream& operator<<(std::ostream& stream, const gca::GCA_trivector& trivector){
        stream << "[";
            stream << " " << trivector.transpose();
        stream << " ]";
        return stream;
    }
}

