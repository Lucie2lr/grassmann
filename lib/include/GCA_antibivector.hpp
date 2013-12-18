#pragma once

#include <Eigen>


namespace gca{
	class GCA_antiscalar;
	class GCA_antivector;
	class GCA_antitrivector;
	class GCA_antiquadvector;
	class GCA_bivector;
	
	class GCA_antibivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_antibivector();
		GCA_antibivector(const double xy, const double xw, const double xz, const double yw, const double yz, const double wz);
		GCA_antibivector(const GCA_antibivector& other);
		
		// Destructeur
		~GCA_antibivector();
		
		GCA_antibivector& operator=(const GCA_antibivector& other);
        bool operator==(const GCA_antibivector& other) const;
        bool operator!=(const GCA_antibivector& other) const;
		GCA_antibivector operator^(const GCA_antiscalar& other) const;
		GCA_antitrivector operator^(const GCA_antivector& other) const;
		GCA_antiquadvector operator^(const GCA_antibivector& other) const;
		GCA_bivector operator~();
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_antibivector& vector);
	
	};
}
