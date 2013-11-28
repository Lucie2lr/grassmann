#pragma once

#include <Eigen>

namespace gca{	
	
	class GCA_vector;
	
	class GCA_scalar{
		public:
			// Constructeurs
			GCA_scalar();
			GCA_scalar(double x);
			GCA_scalar(const GCA_scalar& other);
			
			// Destructeur
			~GCA_scalar();
			
			// Opérateurs
            GCA_scalar& operator=(const GCA_scalar& other);
            GCA_scalar& operator<<(const double& in);
            bool operator==(const GCA_scalar& other) const;
            bool operator!=(const GCA_scalar& other) const;
			GCA_scalar operator^(const GCA_scalar& other) const;
			GCA_vector operator^(const GCA_vector& other) const;
           // operator~() const;
            
			// Autres méthodes
			friend std::ostream& operator<<(std::ostream& stream, const GCA_scalar& vector);
			
        private:
        	double value;
	};
}

