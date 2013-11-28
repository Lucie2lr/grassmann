#include <iostream>

#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"

namespace gca{
			// CONSTRUCTEURS
			GCA_scalar::GCA_scalar()
				: value(1) {}
				
			GCA_scalar::GCA_scalar(const double x)
				: value(x) {}
				
			GCA_scalar::GCA_scalar(const GCA_scalar& other)
				: value(other.value) {}
			
			// DESTRUCTEUR
			GCA_scalar::~GCA_scalar(){}
			
			// OPERATEURS
            GCA_scalar& GCA_scalar::operator=(const GCA_scalar& other){
				this->value = other.value;
			}
			
            GCA_scalar& GCA_scalar::operator<<(const double& in){
				this->value = in;
			}
            
            bool GCA_scalar::operator==(const GCA_scalar& other) const{
				if(this->value == other.value){
					return true;
				}else{
					return false;
				}
           // operator~() const;
			}
            bool GCA_scalar::operator!=(const GCA_scalar& other) const{
				if(this->value == other.value){
					return false;
				}else{
					return true;
				}
			}
			
			GCA_scalar GCA_scalar::operator^(const GCA_scalar& other) const{
				return GCA_scalar(this->value * other.value);
			}
			
			GCA_vector GCA_scalar::operator^(const GCA_vector& other) const{
				GCA_vector A(other);
				for(int i = 0; i < 4; ++i){
					A[i] = this->value * A[i];
				}
				return  A;
			}
            
            // AUTRES METHODES
			std::ostream& operator<<(std::ostream& stream, const GCA_scalar& vector){
					stream << " " << vector.value << " ";
					return stream;
			}
}
