#pragma once

#include <Eigen>

namespace gca{
	class GCA_bivector;
	
	class GCA_vector: public Eigen::VectorXd{
		public:
			// Constructeur
			GCA_vector();
			GCA_vector(int size);
			GCA_vector(double x, double y, double z, double w);
			// Constructeur par recopie
			GCA_vector(const Eigen::VectorXd& other);
			
			// Destructeur
			~GCA_vector();
			
			// Opérateurs
            GCA_vector& operator=(const GCA_vector& other);
            bool operator==(const GCA_vector& other);
            bool operator!=(const GCA_vector& other);
            GCA_bivector operator^(const GCA_vector& other) const;
            
           // operator~() const;
           // operator<<() const;
            
			// Autres méthodes
			
        private:
        	//Attribut
        	
	};
}
