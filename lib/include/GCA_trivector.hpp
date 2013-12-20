#pragma once

#include <Eigen>

namespace gca{
	class GCA_scalar;
	class GCA_vector;
	class GCA_quadvector;
	class GCA_antivector;
	
	class GCA_trivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_trivector();
		GCA_trivector(const double xyw, const double xyz, const double xwz, const double ywz);
		GCA_trivector(const GCA_trivector& other);
		
		// Destructeur
		~GCA_trivector();
		
		GCA_trivector& operator=(const GCA_trivector& other);
        bool operator==(const GCA_trivector& other) const;
        bool operator!=(const GCA_trivector& other) const;
        GCA_trivector operator^(const GCA_scalar& other) const; // A coder
		GCA_quadvector operator^(const GCA_vector& other) const;
		GCA_antivector operator|(const GCA_quadvector& other) const;
		GCA_antibivector operator|(const GCA_trivector& other) const;
		GCA_antitrivector operator|(const GCA_bivector& other) const;
		GCA_antiquadvector operator|(const GCA_vector& other) const;
		GCA_antivector operator~() const;

		double e123() const;
		double e124() const;
		double e134() const;
		double e234() const;
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_trivector& vector);
	
	};
}

