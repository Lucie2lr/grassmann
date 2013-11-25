#pragma once

#include <Eigen>

namespace GCA{
	class Vector: public Eigen::VectorXd{
		public:
			// Constructeur
			Vector();
			Vector(int size);
			// Destructeur
			~Vector();
	};
}
