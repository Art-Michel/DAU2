// #include <SFML/Graphics.hpp>

// int main()
// {
// 	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
// 	sf::CircleShape shape(100.f);
// 	shape.setFillColor(sf::Color::Green);

// 	while (window.isOpen())
// 	{
// 		sf::Event event;
// 		while (window.pollEvent(event))
// 		{
// 			if (event.type == sf::Event::Closed)
// 				window.close();
// 		}

// 		window.clear();
// 		window.draw(shape);
// 		window.display();
// 	}

// 	return 0;
// }

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.h"
#include "player.h"
#include "EntitiesManager.h"

sf::RenderWindow window;

int main()
{
	auto window = sf::RenderWindow{{1280u, 720u}, "wahoo"};
	window.setFramerateLimit(30);

	while (window.isOpen())
	{
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.display();
		std::cout << "Mario!\n";
	}
}

Entity entity;
Entity entity2;
Entity entity3;
Player player;

void Init()
{
	entity = Entity();
	entity2 = Entity();
	entity3 = Entity();
	// player = Player();

	player.init(vec2(500, 400), ".\\Sprites\\char.png");
	auto *ent = static_cast<Entity *>(&player);
	EntitiesManager::GetInstance()->entities.push_back(ent);

	entity.init(vec2(500, 32), ".\\Sprites\\Square.png");
	entity2.init(vec2(564, 32), ".\\Sprites\\Square.png");
	entity3.init(vec2(628, 32), ".\\Sprites\\Square.png");
	EntitiesManager::GetInstance()->entities.push_back(&entity);
	EntitiesManager::GetInstance()->entities.push_back(&entity2);
	EntitiesManager::GetInstance()->entities.push_back(&entity3);
}

void Update(float deltaTime)
{
	EntitiesManager::GetInstance()->Update(deltaTime);
}

void Render()
{
	EntitiesManager::GetInstance()->Draw();

	// std::string str = "x: " + std::to_string(inputs.get_inputs().x) + "\n y: " + std::to_string(inputs.get_inputs().y);
	// App::Print(100, 100, str.c_str());

	// std::string str2 = "length: " + std::to_string(inputs.get_inputs().magnitude());
	// App::Print(100, 60, str2.c_str());
}

void Shutdown()
{
}

/*

//#include "stdafx.h"
#include <string>
//#include "App\app.h"
#include "entity.h"
#include "player.h"
#include "EntitiesManager.h"
#include "imgui.h"

Entity entity;
Entity entity2;
Entity entity3;
Player player;

void Init()
{
	entity = Entity();
	entity2 = Entity();
	entity3 = Entity();
	//player = Player();

	player.init(vec2(500, 400), ".\\Sprites\\char.png");
	auto* ent = static_cast<Entity*>(&player);
	EntitiesManager::GetInstance()->entities.push_back(ent);

	entity.init(vec2(500, 32), ".\\Sprites\\Square.png");
	entity2.init(vec2(564, 32), ".\\Sprites\\Square.png");
	entity3.init(vec2(628, 32), ".\\Sprites\\Square.png");
	EntitiesManager::GetInstance()->entities.push_back(&entity);
	EntitiesManager::GetInstance()->entities.push_back(&entity2);
	EntitiesManager::GetInstance()->entities.push_back(&entity3);
}

void Update(float deltaTime)
{
	EntitiesManager::GetInstance()->Update(deltaTime);
}

void Render()
{
	EntitiesManager::GetInstance()->Draw();

	//std::string str = "x: " + std::to_string(inputs.get_inputs().x) + "\n y: " + std::to_string(inputs.get_inputs().y);
	//App::Print(100, 100, str.c_str());

	//std::string str2 = "length: " + std::to_string(inputs.get_inputs().magnitude());
	//App::Print(100, 60, str2.c_str());
}

void Shutdown()
{

}*/