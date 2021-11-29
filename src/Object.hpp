#if !defined OBJECT_HPP
#define OBJECT_HPP
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>

namespace PhysicsEngine {

	using clock = std::chrono::steady_clock::time_point;

	class Object {
		
		private:
			//In pixels
			Vector position;
			//In pixels/s
			Vector velocity;
			//In pixels/s^2
			Vector acceleration;
			//In kg*pixels/s^2
			Vector force;
			//Mass in grams
			double mass;
			//Total electrical charge in Coulombs
			double charge;
			//Last time the update function was called measured in seconds
			//since the creation of the object
			clock lastTimeUpdated;
			sf::RectangleShape shape;

		public:
			Object(double mass, double charge=0);
			Object(Vector position=Vector {}, Vector velocity=Vector {}, double mass=1000, double charge=0);
			void applyForce(const Vector& appliedForce);
			void update();
			void setShape(sf::RectangleShape& newShape);
			void draw(sf::RenderWindow& window);
			const Vector& getPosition() const { return position; };
			const Vector& getVelocity() const { return velocity; };
			double getMass() const { return mass; };
	};
}
#endif
