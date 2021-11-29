#include "Vector.hpp"
#include <cmath>
#include <iostream> 

namespace PhysicsEngine {

	Vector::Vector() : x {}, y {}
	{}
	Vector::Vector(double x_component, double y_component) : x {x_component}, y {y_component}
	{}
	Vector::Vector(const Vector& v) : x {v.x}, y {v.y}
	{}

	Vector Vector::scale(double scalar) const {
		
		double new_x {x * scalar}, new_y {y * scalar};
		return Vector {new_x, new_y};
	}

	double Vector::magnitude() const {
		return std::sqrt(x*x + y*y);
	}

	Vector Vector::normalize() const {
		double mag {this->magnitude()};
		double new_x {x/mag}, new_y {y/mag};

		return Vector{new_x, new_y};
	}

	void Vector::print() const {
		std::cout << x << " i ";
		if (y >= 0)
			std::cout << "+ ";
		std::cout << y << " j\n";
	}

	Vector Vector::add(Vector v1, Vector v2) {
		return Vector {v1.x + v2.x, v1.y + v2.y};
	}

	double Vector::angle() const {
		if (!x) {
			if (y > 0) return PI/2;
			else return -PI/2;
		}
		else if (x > 0)
			return std::atan(y/x);
		else
			return std::atan(y/x) + PI;
	}

	Vector Vector::rectify() const {
		double new_y {-y};
		return Vector {x, new_y};
	}

	bool Vector::operator<(const Vector& v) const {
		return magnitude() < v.magnitude();
	}

	bool Vector::operator==(const Vector& v) const {
		return magnitude() == v.magnitude();
	}
}
