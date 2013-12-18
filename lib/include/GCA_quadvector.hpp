#pragma once

namespace gca{
	class GCA_scalar;
	class GCA_antiscalar;
	
	class GCA_quadvector{
	public:
		// Constructeur
		GCA_quadvector();
		GCA_quadvector(const double xywz);
		GCA_quadvector(const GCA_quadvector& other);
		
		// Destructeur
		~GCA_quadvector();

		// Getteurs
		const double getValue() const;
		void setValue(const double val);

		// Opérateurs
		GCA_quadvector& operator=(const GCA_quadvector& other);
        GCA_quadvector& operator<<(const double& in);
        bool operator==(const GCA_quadvector& other) const;
        bool operator!=(const GCA_quadvector& other) const;
		GCA_quadvector operator^(const GCA_scalar& other) const;
		GCA_antiscalar operator~();
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_quadvector& vector);

	private: 
		double value;
	
	};
}
