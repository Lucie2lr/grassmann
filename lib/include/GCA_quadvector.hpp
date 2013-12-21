#pragma once

namespace gca{
	class GCA_scalar;
	class GCA_vector;
	class GCA_bivector;
	class GCA_trivector;
	class GCA_antiscalar;
	class GCA_antivector;
	class GCA_antibivector;
	class GCA_antitrivector;
	class GCA_antiquadvector;
	
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
		GCA_antiquadvector operator|(const GCA_scalar& other) const;
		GCA_antitrivector operator|(const GCA_vector& other) const;
		GCA_antibivector operator|(const GCA_bivector& other) const;
		GCA_antivector operator|(const GCA_trivector& other) const;
		GCA_antiscalar operator|(const GCA_quadvector& other) const;
		GCA_antiscalar operator~() const;
		
		//  Autres méthodes
		friend std::ostream& operator<<(std::ostream& stream, const GCA_quadvector& vector);

	private: 
		double value;
	
	};
}
