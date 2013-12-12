#include "GCA_scalar.hpp"
#include "GCA_vector.hpp"
#include "GCA_bivector.hpp"
#include "GCA_trivector.hpp"
#include "GCA_quadvector.hpp"
#include "GCA_antiquadvector.hpp"

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

			// GETTEUR
			const double GCA_scalar::getValue() const{
				return this->value;
			}
			
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
			
			GCA_bivector GCA_scalar::operator^(const GCA_bivector& other) const{
				GCA_bivector A(other);
				for(int i = 0; i < 6; ++i){
					A[i] = this->value * A[i];
				}
				return  A;
			}
			
			GCA_trivector GCA_scalar::operator^(const GCA_trivector& other) const{
				GCA_trivector A(other);
				for(int i = 0; i < 4; ++i){
					A[i] = this->value * A[i];
				}
				return  A;
			}
			
			GCA_quadvector GCA_scalar::operator^(const GCA_quadvector& other) const{
				return GCA_quadvector(this->value * other.getValue());
			}

			GCA_antiquadvector GCA_scalar::operator~(){
				GCA_antiquadvector antiquad;
				antiquad << this->value;
				return antiquad;
			}

			
            
            // AUTRES METHODES
			std::ostream& operator<<(std::ostream& stream, const GCA_scalar& vector){
					stream << " " << vector.value << " ";
					return stream;
			}

}
