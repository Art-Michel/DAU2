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
std::vector<sf::Text> texts;
std::vector<sf::Sprite> sprites;
sf::Clock deltaClock;

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

	player.init(vec2(100, 200), "D:\\Cooding\\cmake-sfml-project\\Sprites\\char.png");
	auto *ent = static_cast<Entity *>(&player);
	EntitiesManager::GetInstance()->entities.push_back(ent);

	entity.init(vec2(500, 32), "D:\\Cooding\\cmake-sfml-project\\Sprites\\Square.png");
	entity2.init(vec2(100, 100), "D:\\Cooding\\cmake-sfml-project\\Sprites\\Square.png");
	entity3.init(vec2(628, 32), "D:\\Cooding\\cmake-sfml-project\\Sprites\\Square.png");
	EntitiesManager::GetInstance()->entities.push_back(&entity);
	EntitiesManager::GetInstance()->entities.push_back(&entity2);
	EntitiesManager::GetInstance()->entities.push_back(&entity3);
}

void Update(float deltaTime)
{
	EntitiesManager::GetInstance()->Update(deltaTime);
}

int main()
{
	auto window = sf::RenderWindow{{1280u, 720u}, "wahoo", sf::Style::Close | sf::Style::Titlebar};
	window.setFramerateLimit(30);
	Init();

	sf::Font silver;
	silver.loadFromFile("D:\\Cooding\\cmake-sfml-project\\fonts\\Silver.ttf");
	silver.setSmooth(false);
	sf::Text text;

	text.setCharacterSize(36);
	text.setFont(silver);
	text.setString("Ouah!!");
	text.setPosition(200.0f, 200.0f);
	while (window.isOpen())
	{
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		Update(deltaClock.restart().asSeconds());

		window.clear();
		window.draw(text);

		// sf::CircleShape shape(100.f);
		// shape.setFillColor(sf::Color::Green);
		// window.draw(shape);

		for (int i = 0; i < EntitiesManager::GetInstance()->entities.size(); i++)
		{
			window.draw(EntitiesManager::GetInstance()->entities[i]->sprite_);
		}

		window.display();
		// std::cout << "Mario!\n";
	}
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