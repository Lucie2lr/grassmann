#pragma once

#include <Eigen>


namespace gca{
	class GCA_trivector;
	class GCA_vector;
	
	class GCA_bivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_bivector();
		GCA_bivector(const GCA_bivector& other);
		
		// Destructeur
		~GCA_bivector();
		
		GCA_bivector& operator=(const GCA_bivector& other);
	/*	operator~();
		operator<<();*/

		GCA_trivector operator^(const GCA_vector& other) const;
		GCA_bivector operator^(const GCA_scalar& other) const;
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_bivector& vector);
	
	};
}
