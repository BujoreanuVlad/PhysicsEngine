#if !defined UNIVERSE_HPP
#define UNIVERSE_HPP
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "ForceField.hpp"

namespace PhysicsEngine {

	class Universe {

		private:
			Object *objects;
			ForceField *fields;
			size_t num_objects, num_fields;
			float width, height;
			sf::RenderWindow window;

		public:
			Universe(const float w=1000, const float h=800);
			Universe(const Universe& u);
			void addObject(const Object& o);
			void addField(const ForceField& ff);
			void update();
			sf::RenderWindow& getWindow() { return window; };
			Object& getObject(size_t index=0);
	};
}
#endif
