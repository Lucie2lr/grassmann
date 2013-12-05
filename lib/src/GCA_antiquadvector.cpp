#include "GCA_antiquadvector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antibivector.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antiscalar.hpp"

namespace gca{
			// CONSTRUCTEURS
			GCA_antiquadvector::GCA_antiquadvector()
				: value(1) {}
				
			GCA_antiquadvector::GCA_antiquadvector(const double x)
				: value(x) {}
				
			GCA_antiquadvector::GCA_antiquadvector(const GCA_antiquadvector& other)
				: value(other.value) {}
			
			// DESTRUCTEUR
			GCA_antiquadvector::~GCA_antiquadvector(){}

			// GETTEUR
			const double GCA_antiquadvector::getValue() const{
				return this->value;
			}
			
			// OPERATEURS
            GCA_antiquadvector& GCA_antiquadvector::operator=(const GCA_antiquadvector& other){
				this->value = other.value;
			}
			
            GCA_antiquadvector& GCA_antiquadvector::operator<<(const double& in){
				this->value = in;
			}
            
            bool GCA_antiquadvector::operator==(const GCA_antiquadvector& other) const{
				if(this->value == other.value){
					return true;
				}else{
					return false;
				}
           // operator~() const;
			}
            bool GCA_antiquadvector::operator!=(const GCA_antiquadvector& other) const{
				if(this->value == other.value){
					return false;
				}else{
					return true;
				}
			}
			
			GCA_antiquadvector GCA_antiquadvector::operator^(const GCA_antiquadvector& other) const{
				return GCA_antiquadvector(this->value * other.value);
			}
			
			GCA_antitrivector GCA_antiquadvector::operator^(const GCA_antitrivector& other) const{
				GCA_antitrivector A(other);
				for(int i = 0; i < 4; ++i){
					A[i] = this->value * A[i];
				}
				return  A;
			}
			
			GCA_antibivector GCA_antiquadvector::operator^(const GCA_antibivector& other) const{
				GCA_antibivector A(other);
				for(int i = 0; i < 6; ++i){
					A[i] = this->value * A[i];
				}
				return  A;
			}
			
			GCA_antivector GCA_antiquadvector::operator^(const GCA_antivector& other) const{
				GCA_antivector A(other);
				for(int i = 0; i < 4; ++i){
					A[i] = this->value * A[i];
				}
				return  A;
			}
			
			GCA_antiscalar GCA_antiquadvector::operator^(const GCA_antiscalar& other) const{
				return GCA_antiscalar(this->value * other.getValue());
			}
            
            // AUTRES METHODES
			std::ostream& operator<<(std::ostream& stream, const GCA_antiquadvector& vector){
					stream << " " << vector.value << " ";
					return stream;
			}
}
