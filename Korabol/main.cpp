#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "PhysicsWorld.h"


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    sf::Clock clock;
    PhysicsWorld world;

    Object object;

    object.Mass = 1;
    object.Position = sf::Vector2f(50, 50);
    object.Velocity = sf::Vector2f(10, 0);;

    world.AddObject(&object);

    sf::CircleShape sphere(5);

    sphere.setPosition(object.Position);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(sphere);
        
        window.display();

        sf::Time time = clock.getElapsedTime();
        clock.restart();
        world.Step(time.asSeconds());
        sphere.setPosition(object.Position);
    }

    return 0;
}