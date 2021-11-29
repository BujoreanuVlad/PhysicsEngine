#if !defined VECTOR_HPP
#define VECTOR_HPP
#include <utility>

namespace PhysicsEngine {

	using namespace std::rel_ops;

	class Vector {

		private:
			double x, y;
		
		public:
			static inline const double PI {3.14159265};
			Vector();
			Vector(double x_component, double y_component);
			Vector(const Vector& v);
			Vector scale(double scalar) const;
			Vector normalize() const;
			//Multiplies the y coord by -1 to compensate for the fact that the
			//y-coord of 0 on the screen is at the top instead of the bottom
			Vector rectify() const;
			double magnitude() const;
			//Gets the angle in radians
			double angle() const;
			void print() const;

			double getX() const { return x; };
			double getY() const { return y; };

			static Vector add(Vector v1, Vector v2);
			bool operator<(const Vector& v) const;
			bool operator==(const Vector& v) const;
	};
}

#endif
