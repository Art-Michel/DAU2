#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.h"
#include "player.h"
#include "EntitiesManager.h"
#include "Tilemap.h"
#include "../imgui-sfml-2.6/imgui-1.90.1/imgui.h"
#include "../imgui-sfml-2.6/imgui-SFML.h"
#include "Background.h"

sf::RenderWindow window;
std::vector<sf::Text> texts;
std::vector<sf::Sprite> sprites;
sf::Clock deltaClock;

Entity entity;
Entity entity2;
Entity entity3;
Player player;

const int level[] = {
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	5, 10, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 11, 5, 5, 5, 5, 5, 5, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 8, 11, 5, 5, 5, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 11, 5, 5, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 11, 5, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 11, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 13, 5, 5, 5, 5, 5, 12, 3, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5, 5, 5, 5, 5, 5, 6, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5, 5, 5, 5, 5, 5, 6, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5, 5, 5, 5, 5, 5, 12, 3, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0, 0, 0, 0, 0, 4, 5,
	5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 0, 0, 0, 0, 0, 4, 5,
	5, 12, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 5, 12, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 5, 5, 12, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 5, 5, 5, 12, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 5, 5, 5, 5, 5, 5, 5, 12, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 5,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

void instBgs(float x, float y, std::vector<Background *> *bgs)
{
	Background *bg;
	bg = new Background();
	// bg->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_1.png", {100, 100});
	bg->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_1.png", {0.1f, 0.2f});
	bgs->push_back(bg);
	Background *bg2;
	bg2 = new Background();
	// bg2->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_2.png", {100, 100});
	bg2->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_2.png", {1.0f, 2.0f});
	bgs->push_back(bg2);
	Background *bg3;
	bg3 = new Background();
	// bg3->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_3.png", {100, 100});
	bg3->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_3.png", {1.5f, 3.0f});
	bgs->push_back(bg3);
	Background *bg4;
	bg4 = new Background();
	// bg4->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_4.png", {100, 100});
	bg4->Init({x, y}, "D:\\Cooding\\cmake-sfml-project\\Sprites\\Enjl-Starry Space Background\\background_4.png", {0.2f, 0.4f});
	bgs->push_back(bg4);
}

void Shutdown()
{
	ImGui::SFML::Shutdown();
}

int main()
{
	auto window = sf::RenderWindow{{256u, 192u}, "DAU!", sf::Style::Close | sf::Style::Titlebar};
	window.setFramerateLimit(60);
	window.setSize({1280u, 960u});
	ImGui::SFML::Init(window);

	sf::Font silver;
	silver.loadFromFile("D:\\Cooding\\cmake-sfml-project\\fonts\\Silver.ttf");
	silver.setSmooth(false);
	sf::Text text;

	text.setCharacterSize(18);
	text.setFont(silver);
	text.setString("Font by poppyworks\nBackgrounds by Enji\nTileset by Chimplement");
	text.setScale(0.4, 0.4);
	text.setPosition(2.0f, 164.0f);

	player.init(vec2(32, 32), "D:\\Cooding\\cmake-sfml-project\\Sprites\\char.png");
	auto *ent = static_cast<Entity *>(&player);
	EntitiesManager::GetInstance()->entities.push_back(ent);

	TileMap map;
	if (!map.load("D:\\Cooding\\cmake-sfml-project\\Sprites\\tiles2.png", sf::Vector2u(8, 8), level, 32, 24))
		return -1;

	std::vector<Background *> backgrounds;
	instBgs(-256.0f, -192.0, &backgrounds);
	instBgs(0, 0, &backgrounds);
	instBgs(-256.0f, 0, &backgrounds);
	instBgs(0, -192.0, &backgrounds);

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

		ImGui::Begin("Main!");
		float f = 1.0f / delta.asSeconds();
		f = roundf(f * 100) * 0.01f;
		std::string s = std::to_string(f);
		std::string s2 = std::string(" fps");
		ImGui::Text((s + s2).c_str());
		ImGui::Text("Font: https://poppyworks.itch.io/silver\nBackground: https://enjl.itch.io/background-starry-space\nTileset: https://chimplement.itch.io/crater-caverns");
		ImGui::End();

		// Update Entities
		EntitiesManager::GetInstance()->Update(delta.asSeconds());
		// Update Backgrounds
		for (size_t i = 0; i < backgrounds.size(); i++)
			backgrounds[i]->update(delta.asSeconds());

		window.clear();
		// Draw Backgrounds
		for (size_t i = 0; i < backgrounds.size(); i++)
			window.draw(backgrounds[i]->sprite_);
		// Draw Sprites
		for (int i = 0; i < EntitiesManager::GetInstance()->entities.size(); i++)
			window.draw(EntitiesManager::GetInstance()->entities[i]->sprite_);

		// Draw map
		window.draw(map);
		// Draw text
		window.draw(text);

		// Display window
		ImGui::SFML::Render(window);
		window.display();
	}
	Shutdown();
}