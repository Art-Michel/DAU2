// #include "stdafx.h"
#include "EntitiesManager.h"

EntitiesManager *EntitiesManager::GetInstance()
{
	if (instance == nullptr)
		instance = new EntitiesManager();
	return instance;
}

// void EntitiesManager::Init(float delta)
//{
//	for (int i = 0; i< entities.size(); i++)
//	{
//		entities[i]->init();
//	}
// }

void EntitiesManager::Update(float delta)
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->update(delta);
	}
}

void EntitiesManager::Draw()
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->draw();
	}
}