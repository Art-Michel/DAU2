#pragma once
#include <vector>
#include "entity.h"

class EntitiesManager
{
	EntitiesManager() {}

public:
	static inline EntitiesManager *instance = nullptr;
	std::vector<Entity *> entities;
	static EntitiesManager *GetInstance();
	void Update(float delta);
	void Draw();
	void LoadMap();
	sf::Texture m_tileset;
};