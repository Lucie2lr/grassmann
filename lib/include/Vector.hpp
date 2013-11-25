#pragma once

namespace GCA{
	class Vector{			
		public:
		
			// Constructeur
			Vector();
			Vector(float xCoord, float yCoord);
			// Destructeur
			~Vector();

			operator=();
			operator^();
			operator~();
			operator<<();
	};
}
