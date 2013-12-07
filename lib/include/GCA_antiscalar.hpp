#pragma once

namespace gca{
	class GCA_antiquadvector;
	class GCA_quadvector;
	
	class GCA_antiscalar{
	public:
		// Constructeur
		GCA_antiscalar();
		GCA_antiscalar(const double val);
		GCA_antiscalar(const GCA_antiscalar& other);
		
		// Destructeur
		~GCA_antiscalar();

		// Getteurs
		const double getValue() const;
		void setValue(const double val);

		// Opérateurs
		GCA_antiscalar& operator=(const GCA_antiscalar& other);
        GCA_antiscalar& operator<<(const double& in);
        bool operator==(const GCA_antiscalar& other) const;
        bool operator!=(const GCA_antiscalar& other) const;
		GCA_antiscalar operator^(const GCA_antiquadvector& other) const;
		GCA_quadvector operator~(void);
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_antiscalar& antiscalar);

	private: 
		double value;
	
	};
}
