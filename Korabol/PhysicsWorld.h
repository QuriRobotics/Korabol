#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

struct Object
{
	sf::Vector2f Position;
	sf::Vector2f Velocity;
	sf::Vector2f Force;
	float Mass;
};

class PhysicsWorld
{
private:
	std::vector<Object*> m_objects;
	sf::Vector2f m_gravity = sf::Vector2f(0, 9.81f);

public:
	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void Step(float dt);
};

