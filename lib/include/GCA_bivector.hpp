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
		GCA_bivector(const double xy,const double xz,const double xw,const double yz,const double yw,const double zw);
		GCA_bivector(const GCA_bivector& other);
		
		// Destructeur
		~GCA_bivector();
		
		GCA_bivector& operator=(const GCA_bivector& other);
        bool operator==(const GCA_bivector& other) const;
        bool operator!=(const GCA_bivector& other) const;
		GCA_trivector operator^(const GCA_vector& other) const;
		GCA_bivector operator^(const GCA_scalar& other) const;
		GCA_quadvector operator^(const GCA_bivector& other) const;
		GCA_antibivector operator~();

		GCA_vector u() const;
		GCA_vector v() const;

		double e12() const;
		double e13() const;
		double e14() const;
		double e23() const;
		double e24() const;
		double e34() const;
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_bivector& vector);
	
	};
}
