#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.h"
#include "player.h"
#include "EntitiesManager.h"
#include "../imgui-sfml-2.6/imgui-1.90.1/imgui.h"
#include "../imgui-sfml-2.6/imgui-SFML.h"

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
	ImGui::Begin("Main!");
	float f = 1.0f / deltaTime;
	f = roundf(f * 100) * 0.01f;
	std::string s = std::to_string(f);
	std::string s2 = std::string(" fps");
	ImGui::Text((s + s2).c_str());
	ImGui::End();
}

void Shutdown()
{
	ImGui::SFML::Shutdown();
}

int main()
{
	auto window = sf::RenderWindow{{1280u, 720u}, "wahoo", sf::Style::Close | sf::Style::Titlebar};
	window.setFramerateLimit(1000);
	Init();
	ImGui::SFML::Init(window);

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
			ImGui::SFML::ProcessEvent(window, event);
		}

		auto delta = deltaClock.restart();
		ImGui::SFML::Update(window, delta);
		Update(delta.asSeconds());
		// ImGui::Begin("Hello, world!");
		// ImGui::Text("Some Text!");
		// static bool showText = false;
		// if (ImGui::Button("Look at this pretty button"))
		// 	showText = !showText;
		// if (showText)
		// 	ImGui::Text("More Text!");
		// ImGui::ShowDemoWindow();
		// ImGui::End();

		window.clear();
		for (int i = 0; i < EntitiesManager::GetInstance()->entities.size(); i++)
		{
			window.draw(EntitiesManager::GetInstance()->entities[i]->sprite_);
		}
		window.draw(text);
		ImGui::SFML::Render(window);

		window.display();
	}
	Shutdown();
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