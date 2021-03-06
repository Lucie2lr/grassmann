#pragma once

#include <Eigen>

namespace gca{	
	
	class GCA_vector;
	class GCA_bivector;
	class GCA_trivector;
	class GCA_quadvector;
	class GCA_antiquadvector;
	
	class GCA_scalar{
		public:
			// Constructeurs
			GCA_scalar();
			GCA_scalar(double x);
			GCA_scalar(const GCA_scalar& other);
			
			// Destructeur
			~GCA_scalar();

			// Getteur
			const double getValue() const;
			
			// Opérateurs
            GCA_scalar& operator=(const GCA_scalar& other);
            GCA_scalar& operator<<(const double& in);
            bool operator==(const GCA_scalar& other) const;
            bool operator!=(const GCA_scalar& other) const;
			GCA_scalar operator^(const GCA_scalar& other) const;
			GCA_vector operator^(const GCA_vector& other) const;
			GCA_bivector operator^(const GCA_bivector& other) const;
			GCA_trivector operator^(const GCA_trivector& other) const;
			GCA_quadvector operator^(const GCA_quadvector& other) const;
			GCA_antiquadvector operator|(const GCA_quadvector& other) const; 
            GCA_antiquadvector operator~() const;
            
			// Autres méthodes
			friend std::ostream& operator<<(std::ostream& stream, const GCA_scalar& vector);
			
        private:
        	double value;
	};
}

