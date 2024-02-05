#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.h"
#include "player.h"
#include "EntitiesManager.h"
#include "Tilemap.h"
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

const int level[] = {
	34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
	34, 129, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 130, 34, 34, 34, 34, 34, 34, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 66, 66, 130, 34, 34, 34, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 130, 34, 34, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 130, 34, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 130, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 162, 34, 34, 34, 34, 34, 161, 3, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34, 34, 34, 34, 34, 34, 34, 35, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34, 34, 34, 34, 34, 34, 34, 35, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34, 34, 34, 34, 34, 34, 34, 161, 3, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34, 34, 34, 34, 34, 34, 34, 34, 35, 0, 0, 0, 0, 0, 33, 34,
	34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 66, 66, 66, 66, 66, 66, 66, 66, 67, 0, 0, 0, 0, 0, 33, 34,
	34, 161, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 34, 161, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 34, 34, 161, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 34, 34, 34, 161, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 34, 34, 34, 34, 34, 34, 34, 161, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 34,
	34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 161, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 162, 34,
	34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34};

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
	window.setFramerateLimit(100);
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

	TileMap map;
	if (!map.load("D:\\Cooding\\cmake-sfml-project\\Sprites\\tiles.png", sf::Vector2u(8, 8), level, 32, 24))
		return -1;

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

		window.clear();
		for (int i = 0; i < EntitiesManager::GetInstance()->entities.size(); i++)
		{
			window.draw(EntitiesManager::GetInstance()->entities[i]->sprite_);
		}
		window.draw(text);
		window.draw(map);
		ImGui::SFML::Render(window);

		window.display();
	}
	Shutdown();
}