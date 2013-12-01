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

	/*	operator~();
		operator<<();*/

		//GCA_quadvector operator^(const & other) const;
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_trivector& vector);
	
	};
}

