#pragma once

#include <Eigen>

namespace gca{
	class GCA_vector;
	class GCA_quadvector;
	class GCA_antivector;
	
	class GCA_trivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_trivector();
		GCA_trivector(const GCA_trivector& other);
		
		// Destructeur
		~GCA_trivector();
		
		GCA_trivector& operator=(const GCA_trivector& other);
        bool operator==(const GCA_trivector& other) const;
        bool operator!=(const GCA_trivector& other) const;
		GCA_quadvector operator^(const GCA_vector& other) const;
		GCA_antivector operator~();
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_trivector& vector);
	
	};
}

