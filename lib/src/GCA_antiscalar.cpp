#include <iostream>

#include "GCA_antiscalar.hpp"
#include "GCA_antibivector.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_quadvector.hpp"

namespace gca{
	GCA_antiscalar::GCA_antiscalar()
		:value(1){}

	GCA_antiscalar::GCA_antiscalar(const double xywz)
		:value(xywz){}

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

	
	GCA_antiscalar GCA_antiscalar::operator^(const GCA_antiscalar& other) const{
		return GCA_antiscalar(this->value * other.getValue());
	}
	
	GCA_antiquadvector GCA_antiscalar::operator^(const GCA_antiquadvector& other) const{
		return GCA_antiquadvector(this->value * other.getValue());
	}

	GCA_antitrivector GCA_antiscalar::operator^(const GCA_antitrivector& other) const{
		GCA_antitrivector A(other);
		for(int i = 0; i < 4; ++i){
			A[i] = this->value * A[i];
		}
		return  A;
	}

	GCA_antibivector GCA_antiscalar::operator^(const GCA_antibivector& other) const{
		GCA_antibivector A(other);
		for(int i = 0; i < 6; ++i){
			A[i] = this->value * A[i];
		}
		return  A;
	}

	GCA_antivector GCA_antiscalar::operator^(const GCA_antivector& other) const{
		GCA_antivector A(other);
		for(int i = 0; i < 4; ++i){
			A[i] = this->value * A[i];
		}
		return  A;
	}

	GCA_quadvector GCA_antiscalar::operator~(){
		GCA_quadvector quadA;
		quadA << this->value;
		return quadA;
	}

	// AUTRES METHODES
	std::ostream& operator<<(std::ostream& stream, const GCA_antiscalar& antiscalar){
		stream << " " << antiscalar.value << " |1| ";
		return stream;
	}
}
