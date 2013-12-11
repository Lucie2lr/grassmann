#pragma once

#include <Eigen>


namespace gca{
	class GCA_scalar;
	class GCA_vector;
	class GCA_trivector;
	class GCA_quadvector;
	class GCA_antibivector;
	
	class GCA_bivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_bivector();
		GCA_bivector(const GCA_bivector& other);
		
		// Destructeur
		~GCA_bivector();
		
		GCA_bivector& operator=(const GCA_bivector& other);
		GCA_trivector operator^(const GCA_vector& other) const;
		GCA_bivector operator^(const GCA_scalar& other) const;
		GCA_quadvector operator^(const GCA_bivector& other) const;
		GCA_antibivector operator~();
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_bivector& vector);
	
	};
}
