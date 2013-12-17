#pragma once

#include <Eigen>

namespace gca{
	class GCA_antiscalar;
	class GCA_antibivector;
	class GCA_antitrivector;
	class GCA_antiquadvector;
	class GCA_trivector;
	
	class GCA_antivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_antivector();
		GCA_antivector(const GCA_antivector& other);
		
		// Destructeur
		~GCA_antivector();
		
		GCA_antivector& operator=(const GCA_antivector& other);
        bool operator==(const GCA_antivector& other) const;
        bool operator!=(const GCA_antivector& other) const;
		GCA_antivector operator^(const GCA_antiscalar& other) const;
		GCA_antibivector operator^(const GCA_antivector& other) const;
		GCA_antitrivector operator^(const GCA_antibivector& other) const;
		GCA_antiquadvector operator^(const GCA_antitrivector& other) const;
		GCA_trivector operator~(void);

		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_antivector& GCA_antivector);
	
	};
}

