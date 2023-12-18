#pragma once
#include <vector>
#include "entity.h"

class EntitiesManager
{
	EntitiesManager(){}

public:
	static inline EntitiesManager* instance = nullptr;
	std::vector<Entity*> entities;
	static EntitiesManager* EntitiesManager::GetInstance();
	void Update(float delta);
	void Draw();
};