#pragma once

#include <Eigen>

namespace gca{
	
	class GCA_bivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_bivector();
		GCA_bivector(GCA_bivector& other);
		
		// Destructeur
		~GCA_bivector();
		
	/*	operator=();
		TriVector operator^(const BiVector& other) const;
		operator~();
		operator<<();*/
	};
}
