#pragma once

#include <Eigen>

namespace GCA{
	class BiVector;
	
	class Vector: public Eigen::VectorXd{
		public:
			// Constructeur
			Vector();
			Vector(int size);
			Vector(double x, double y, double z, double w);
			// Constructeur par recopie
			Vector(const Eigen::VectorXd& other);
			
			// Destructeur
			~Vector();
			
			// Opérateurs
            Vector& operator=(const Vector& other);
            bool operator==(const Vector& other);
            bool operator!=(const Vector& other);
            BiVector operator^(const Vector& other) const;
            
           // operator~() const;
           // operator<<() const;
            
			// Autres méthodes
			
        private:
        	//Attribut
        	
	};
}
