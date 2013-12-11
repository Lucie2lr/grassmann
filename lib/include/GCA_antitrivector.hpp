#pragma once

#include <Eigen>

namespace gca{
	class GCA_antiscalar;
	class GCA_antivector;
	class GCA_antiquadvector;
	class GCA_vector;
	
	class GCA_antitrivector: public Eigen::Vector4d{
		public:
			// Constructeur
			GCA_antitrivector();
			GCA_antitrivector(const double x,const double y,const double z,const double w);
			GCA_antitrivector(const GCA_antitrivector& other);
			
			// Destructeur
			~GCA_antitrivector();
			
			// Opérateurs
            GCA_antitrivector& operator=(const GCA_antitrivector& other);
            bool operator==(const GCA_antitrivector& other) const;
            bool operator!=(const GCA_antitrivector& other) const;
            GCA_antitrivector operator^(const GCA_antiscalar& other) const;
            GCA_antiquadvector operator^(const GCA_antivector& other) const;
			GCA_vector operator~();
            
            // Autres méthodes
			friend std::ostream& operator<<(std::ostream& stream, const GCA_antitrivector& vector);
			int size();

        private:
        	
	};
}
