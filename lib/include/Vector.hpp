#pragma once

namespace GCA{
	class Vector: public VectorXD{			
		public:
		
			// Constructeur
			Vector();
			Vector(float xCoord, float yCoord);
			// Destructeur
			~Vector();
	};
}
