#if !defined FORCE_FIELD_HPP
#define FORCE_FIELD_HPP
#include "Object.hpp"
#include "Vector.hpp"
#include <vector>

namespace PhysicsEngine {

	class ForceField {

		private:
			float x, y;
			float width, height;
			Vector v;

		public:
			ForceField() = default;
			ForceField(float x_, float y_, float width_, float height_, Vector& v_) : x {x_}, y {y_}, width {width_}, height {height_}, v {v_} {}
			void applyForce(Object &object) const;
			bool contains(const Object& object) const;
	};
}

#endif
