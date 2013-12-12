#pragma once

#include <Eigen>

namespace gca{
	class GCA_antitrivector;
	class GCA_antiscalar;
	class GCA_trivector;
	
	class GCA_antivector: public Eigen::VectorXd{
	public:
		// Constructeur
		GCA_antivector();
		GCA_antivector(const GCA_antivector& other);
		
		// Destructeur
		~GCA_antivector();
		
		GCA_antivector& operator=(const GCA_antivector& other);
		GCA_antiscalar operator^(const GCA_antitrivector& other) const;
		GCA_trivector operator~(void);

		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_antivector& GCA_antivector);
	
	};
}

