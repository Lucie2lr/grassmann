#pragma once

#include <Eigen>


namespace gca{
	class GCA_antiquadvector;
	class GCA_antitrivector;
	class GCA_antivector;
	class GCA_antiscalar;
	class GCA_bivector;
	
	class GCA_antibivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_antibivector();
		GCA_antibivector(const GCA_antibivector& other);
		
		// Destructeur
		~GCA_antibivector();
		
		GCA_antibivector& operator=(const GCA_antibivector& other);
		GCA_antivector operator^(const GCA_antitrivector& other) const;
		GCA_antibivector operator^(const GCA_antiquadvector& other) const;
		GCA_antiscalar operator^(const GCA_antibivector& other) const;
		GCA_bivector operator~(void);
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_antibivector& vector);
	
	};
}
