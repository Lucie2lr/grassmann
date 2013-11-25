#include <iostream>

#include "Vector.hpp"

namespace GCA{

	Vector::Vector()
		: Eigen::VectorXd(){
	}
	
	Vector::Vector(int size)
		: Eigen::VectorXd(size){
	}
			
	Vector::~Vector(){}
}
