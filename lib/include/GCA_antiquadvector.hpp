#pragma once

#include <Eigen>

namespace gca{	
	
	class GCA_antitrivector;
	class GCA_antibivector;
	class GCA_antivector;
	class GCA_antiscalar;
	class GCA_scalar;
	
	class GCA_antiquadvector{
		public:
			// Constructeurs
			GCA_antiquadvector();
			GCA_antiquadvector(double x);
			GCA_antiquadvector(const GCA_antiquadvector& other);
			
			// Destructeur
			~GCA_antiquadvector();

			// Getteur
			const double getValue() const;
			
			// Opérateurs
            GCA_antiquadvector& operator=(const GCA_antiquadvector& other);
            GCA_antiquadvector& operator<<(const double& in);
            bool operator==(const GCA_antiquadvector& other) const;
            bool operator!=(const GCA_antiquadvector& other) const;
			GCA_antiquadvector operator^(const GCA_antiquadvector& other) const;
			GCA_antitrivector operator^(const GCA_antitrivector& other) const;
			GCA_antibivector operator^(const GCA_antibivector& other) const;
			GCA_antivector operator^(const GCA_antivector& other) const;
			GCA_antiscalar operator^(const GCA_antiscalar& other) const;
            GCA_scalar operator~();
            
			// Autres méthodes
			friend std::ostream& operator<<(std::ostream& stream, const GCA_antiquadvector& vector);
			
        private:
        	double value;
	};
}

