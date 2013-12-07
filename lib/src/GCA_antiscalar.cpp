#include <iostream>

#include "GCA_antiscalar.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_quadvector.hpp"

namespace gca{
	GCA_antiscalar::GCA_antiscalar()
		:value(1){}

	GCA_antiscalar::GCA_antiscalar(const double val)
		:value(val){}

	GCA_antiscalar::GCA_antiscalar(const GCA_antiscalar& other)
		:value(other.value){}
		
	// Destructeur
	GCA_antiscalar::~GCA_antiscalar(){}
		
	// Getteurs
	const double GCA_antiscalar::getValue() const{
		return this->value;
	}

	void GCA_antiscalar::setValue(const double val){
		this->value = val;
	}

	// Opérateurs	
	GCA_antiscalar& GCA_antiscalar::operator=(const GCA_antiscalar& other){
		this->value = other.value;
	}

	GCA_antiscalar& GCA_antiscalar::operator<<(const double& in){
		this->value = in;
	}
            
    bool GCA_antiscalar::operator==(const GCA_antiscalar& other) const{
		if(this->value == other.value){
			return true;
		}else{
			return false;
		}
	}

    bool GCA_antiscalar::operator!=(const GCA_antiscalar& other) const{
		if(this->value == other.value){
			return false;
		}else{
			return true;
		}
	}

	GCA_antiscalar GCA_antiscalar::operator^(const GCA_antiquadvector& other) const{
		return GCA_antiscalar(this->value * other.getValue());
	}

	GCA_quadvector GCA_antiscalar::operator~(void){
		GCA_quadvector quadA;
		quadA << this->value;
		return quadA;
	}

	// AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const GCA_antiscalar& antiscalar){
		stream << " " << antiscalar.value << " ";
		return stream;
	}
}
