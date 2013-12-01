#pragma once

#include <Eigen>


namespace gca{
	//struct GCA_trivector;
	struct GCA_vector;
	
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

		//GCA_trivector operator^(const GCA_bivector& other) const;
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_bivector& vector);
	
	};
}
