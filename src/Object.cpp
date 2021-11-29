#include "Object.hpp"
#include "Vector.hpp"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace PhysicsEngine {

	Object::Object(double m, double c) : mass {m}, charge {c}
	{
		lastTimeUpdated = std::chrono::steady_clock::now();
		position = Vector {};
		velocity = Vector {};
		acceleration = Vector {};
		force = Vector {};
		shape = sf::RectangleShape(sf::Vector2f(100, 50));
		shape.setFillColor(sf::Color::Black);
	}

	Object::Object(Vector p, Vector v, double m, double c) : position {p}, mass {m}, charge {c}
	{
		velocity = v.rectify();
		lastTimeUpdated = std::chrono::steady_clock::now();
		acceleration = Vector {};
		force = Vector {};
		shape = sf::RectangleShape(sf::Vector2f(100, 50));
		shape.setFillColor(sf::Color::Black);
	}

	void Object::applyForce(const Vector& appliedForce) {
		force = Vector::add(force, appliedForce.rectify());
	}

	void Object::update() {

		if (mass) {
			//1'000 for the conversion from grams to kg
			acceleration = force.scale(1'000/mass);
		}

		force = Vector {};

		clock currentTime {std::chrono::steady_clock::now()};
		double elapsedTime {static_cast<double> (std::chrono::duration_cast<std::chrono::microseconds>(currentTime - lastTimeUpdated).count())};
		elapsedTime /= 1'000'000;

		velocity = Vector::add(velocity, acceleration.scale(elapsedTime));

		position = Vector::add(position, velocity.scale(elapsedTime));

		lastTimeUpdated = currentTime;
	}

	void Object::setShape(sf::RectangleShape& newShape) {
		shape = newShape;
	}

	void Object::draw(sf::RenderWindow& window) {
		shape.setPosition(sf::Vector2f(position.getX(), position.getY()));
		window.draw(shape);
	}
}
