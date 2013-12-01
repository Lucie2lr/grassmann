#pragma once

#include <Eigen>

namespace gca{
	
	class GCA_trivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_trivector();
		GCA_trivector(GCA_trivector& other);
		
		// Destructeur
		~GCA_trivector();
		
		GCA_trivector& operator=(const GCA_trivector& other);
	
	};
}
