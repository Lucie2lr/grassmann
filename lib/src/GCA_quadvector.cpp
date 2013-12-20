#include <iostream>

#include "grassmanCayley.hpp"

namespace gca{
	GCA_quadvector::GCA_quadvector()
		:value(1){}

	GCA_quadvector::GCA_quadvector(const double xywz)
		:value(xywz){}

	GCA_quadvector::GCA_quadvector(const GCA_quadvector& other)
		:value(other.value){}
		
	// Destructeur
	GCA_quadvector::~GCA_quadvector(){}
		
	// Getteurs
	const double GCA_quadvector::getValue() const{
		return this->value;
	}

	void GCA_quadvector::setValue(const double val){
		this->value = val;
	}

	// Opérateurs	
	GCA_quadvector& GCA_quadvector::operator=(const GCA_quadvector& other){
		this->value = other.value;
	}

	GCA_quadvector& GCA_quadvector::operator<<(const double& in){
		this->value = in;
	}
            
    bool GCA_quadvector::operator==(const GCA_quadvector& other) const{
		if(this->value == other.value){
			return true;
		}else{
			return false;
		}
	}

    bool GCA_quadvector::operator!=(const GCA_quadvector& other) const{
		if(this->value == other.value){
			return false;
		}else{
			return true;
		}
	}

	GCA_quadvector GCA_quadvector::operator^(const GCA_scalar& other) const{
		return GCA_quadvector(this->value * other.getValue());
	}

	GCA_antiquadvector GCA_quadvector::operator|(const GCA_scalar& other) const{
		return GCA_antiquadvector((~(*this)).getValue() * (~other).getValue());
	}


	GCA_antitrivector GCA_quadvector::operator|(const GCA_vector& other) const{
		GCA_antitrivector A(~other);
		for(int i = 0; i < 4; ++i){
			A[i] = (~(*this)).getValue() * A[i];
		}
		return  A;
	}


	GCA_antibivector GCA_quadvector::operator|(const GCA_bivector& other) const{
		GCA_antibivector A(~other);
		for(int i = 0; i < 6; ++i){
			A[i] = (~(*this)).getValue() * A[i];
		}
		return  A;
	}


	GCA_antivector GCA_quadvector::operator|(const GCA_trivector& other) const{
		GCA_antivector A(~other);
		for(int i = 0; i < 4; ++i){
			A[i] = (~(*this)).getValue() * A[i];
		}
		return  A;
	}

	GCA_antiscalar GCA_quadvector::operator|(const GCA_quadvector& other) const{
		return GCA_antiscalar((~(*this)).getValue() * (~other).getValue());
	}

	GCA_antiscalar GCA_quadvector::operator~() const{
		GCA_antiscalar antia;
		antia << this->value;
		return antia;
	}



	// AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const GCA_quadvector& vector){
		stream << " " << vector.value << " |e1234|";
		return stream;
	}
}
