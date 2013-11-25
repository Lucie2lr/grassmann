#include "Vector.hpp"
#include "BiVector.hpp"

namespace GCA{

	Vector::Vector(){
		VectorXD();}
	Vector::Vector(float xCoord, float yCoord){
		VectorXD(xCoord, yCoord);
	}		
	Vector::~Vector(){}
}
