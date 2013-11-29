#pragma once

#include <Eigen>

struct GCA_trivector;

namespace gca{
	
	class GCA_bivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_bivector();
		GCA_bivector(GCA_bivector& other);
		
		// Destructeur
		~GCA_bivector();
		
		GCA_bivector& operator=(const GCA_bivector& other);
	/*	operator~();
		operator<<();*/

		GCA_trivector operator^(const GCA_bivector& other) const;
	
	};
}
