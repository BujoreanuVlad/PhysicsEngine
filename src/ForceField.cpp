#include "ForceField.hpp"

namespace PhysicsEngine {

	void ForceField::applyForce(Object &object) const {
		object.applyForce(v);
	}

	bool ForceField::contains(const Object& object) const {

		double oX {object.getPosition().getX()};
		double oY {object.getPosition().getY()}; 

		return (oX >= x) && (oX <= x + width) && (oY >= y) && (oY <= y + height);
	}
}
