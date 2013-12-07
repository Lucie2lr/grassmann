#include <iostream>

#include "GCA_quadvector.hpp"
#include "GCA_scalar.hpp"
#include "GCA_antiscalar.hpp"

namespace gca{
	GCA_quadvector::GCA_quadvector()
		:value(1){}

	GCA_quadvector::GCA_quadvector(const double val)
		:value(val){}

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

	GCA_antiscalar GCA_quadvector::operator~(void){
		GCA_antiscalar antia;
		antia << this->value;
		return antia;
	}

	// AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const GCA_quadvector& vector){
		stream << " " << vector.value << " ";
		return stream;
	}
}
