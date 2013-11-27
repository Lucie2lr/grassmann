#pragma once

#include <Eigen>
#include "BiVector.hpp"

namespace GCA{
	class Vector: public Eigen::VectorXd{
		public:
			// Constructeur
			Vector();
			Vector(int size);
			Vector(double e1, double e2, double e3, double e4);
			// Destructeur
			~Vector();

            Vector operator=(const Vector& other) const;
            BiVector operator^(const Vector& other) const;
           // operator~() const;
           // operator<<() const;

        private:
        	//Attribut
        	
	};
}
