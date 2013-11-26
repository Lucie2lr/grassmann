#pragma once

#include <Eigen>
#include "BiVector.hpp"

namespace GCA{
	class Vector: public Eigen::VectorXd{
		public:
			// Constructeur
			Vector();
			Vector(int size);
			// Destructeur
			~Vector();

            Vector& operator=(const Vector& other) const;
            BiVector& operator^(const Vector& other) const;
           // operator~() const;
           // operator<<() const;

        private:
        	//Attribut
        	float x;
        	float y;
	};
}
