#include "GCA_bivector.hpp"

namespace gca{
	GCA_bivector::GCA_bivector()
		: Eigen::VectorXd(6) {}
	
	GCA_bivector::GCA_bivector(GCA_bivector& other)
		: Eigen::VectorXd(other) {}

	GCA_bivector::~GCA_bivector()
	{}
}
