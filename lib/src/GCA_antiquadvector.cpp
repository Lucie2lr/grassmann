#include "GCA_antiquadvector.hpp"
#include "GCA_antitrivector.hpp"
#include "GCA_antibivector.hpp"
#include "GCA_antivector.hpp"
#include "GCA_antiscalar.hpp"
#include "GCA_scalar.hpp"

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

			void GCA_antiquadvector::setValue(const double val){
				this->value = val;
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
			
			GCA_antiquadvector GCA_antiquadvector::operator^(const GCA_antiscalar& other) const{
				return GCA_antiquadvector(this->value * other.getValue());
			}

			GCA_scalar GCA_antiquadvector::operator~() const{
				GCA_scalar a;
				a << this->value;
				return a;
			}
			
            
            // AUTRES METHODES
			std::ostream& operator<<(std::ostream& stream, const GCA_antiquadvector& vector){
					stream << " " << vector.value << " |ē1234| ";
					return stream;
			}
}
