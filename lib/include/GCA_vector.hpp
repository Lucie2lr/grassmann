#pragma once

#include <Eigen>

namespace gca{
	class GCA_scalar;
	class GCA_bivector;
	
	class GCA_vector: public Eigen::Vector4d{
		public:
			// Constructeur
			GCA_vector();
			GCA_vector(const double x,const double y,const double z,const double w);
			GCA_vector(const GCA_vector& other);
			
			// Destructeur
			~GCA_vector();
			
			// Opérateurs
            GCA_vector& operator=(const GCA_vector& other);
            bool operator==(const GCA_vector& other) const;
            bool operator!=(const GCA_vector& other) const;
            GCA_vector operator^(const GCA_scalar& other) const;
            GCA_bivector operator^(const GCA_vector& other) const;
			// operator~() const;
            
            // Autres méthodes
			friend std::ostream& operator<<(std::ostream& stream, const GCA_vector& vector);
			int size();

        private:
        	
	};
}
