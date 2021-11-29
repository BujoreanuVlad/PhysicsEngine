#include "Universe.hpp"
#include "Object.hpp"
#include <SFML/Graphics.hpp>

namespace PhysicsEngine {

	Universe::Universe(const float w, const float h) : width {w}, height {h}, objects {nullptr}
	{
		window.create(sf::VideoMode(w, h), "Universe");
		num_objects = 0;
		num_fields = 0;
	}

	Universe::Universe(const Universe& u) : width{u.width}, height{u.height}, num_objects{u.num_objects}
	{
		window.create(sf::VideoMode(u.width, u.height), "Universe");
		if (u.objects == nullptr)
			objects = nullptr;
		else {
			objects = new Object[u.num_objects];
			for (size_t i {}; i < u.num_objects; i++)
				objects[i] = u.objects[i];
		}
	}
		
	void Universe::addObject(const Object& o) {
		Object *buff = new Object[++num_objects];
		for (size_t i {}; i <  num_objects-1; i++)
			buff[i] = objects[i];
		buff[num_objects-1] = o;
		if (objects != nullptr)
			delete[] objects;
		objects = buff;
	}

	void Universe::addField(const ForceField& ff) {
		ForceField *buff = new ForceField[++num_fields];
		for (size_t i {}; i <  num_fields-1; i++)
			buff[i] = fields[i];
		buff[num_fields-1] = ff;
		if (fields != nullptr)
			delete[] fields;
		fields = buff;
	}
	void Universe::update() {

		window.clear(sf::Color::White);

		for (size_t i {}; i < num_objects; i++) {
			
			for (size_t j {}; j < num_fields; j++) {
				if (fields[j].contains(objects[i])) {
					fields[j].applyForce(objects[i]);
				}
			}

			objects[i].update();
			objects[i].draw(window);
		}
		window.display();
	}

	Object& Universe::getObject(size_t index) {
		if (index < num_objects)
			return objects[index];
		return objects[0];
	}
}
