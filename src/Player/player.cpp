// #include "stdafx.h"
#include <string>
// #include "App\app.h"
#include "player.h"
#include <algorithm>
#include "EntitiesManager.h"
#include "../imgui-sfml-2.6/imgui-1.90.1/imgui.h"
#include "../imgui-sfml-2.6/imgui-SFML.h"
#include <iostream>

Player::Player() : fsm(*this)
{
}

void Player::init(const vec2 &pos, const char *path)
{
	inputs = Inputs();
	Entity::init(pos, path);
	speed_ = 60.0f;

	Colbox = {6, 7};

	// sf::Font silver;
	// silver.loadFromFile("src/fonts/silver.ttf");
}

void Player::update(float delta)
{
	inputs.register_inputs();
	velocity_ = inputs.get_inputs();

	colliding = false;
	check_collisions();

	Entity::update(delta);
	ImGui::Begin("Player");
	std::string vel = "velocity.x = " + std::to_string(velocity_.x);
	ImGui::Text(vel.c_str());
	std::string vel2 = "velocity.y = " + std::to_string(velocity_.y);
	ImGui::Text(vel2.c_str());

	std::string pos = "Pos.x = " + std::to_string(Pos.x);
	ImGui::Text(pos.c_str());
	std::string pos2 = "Pos.y = " + std::to_string(Pos.y);
	ImGui::Text(pos2.c_str());
	ImGui::End();

	// ImGui::Begin("Test");
	// vec2 a = {0.0f, 1.0f};
	// vec2 b = {1.0f, 0.0f};
	// std::string s3 = "dot = " + std::to_string(dot(velocity_, a));
	// ImGui::Text(s3.c_str());
	// std::string s4 = "dot = " + std::to_string(dot(velocity_, b));
	// ImGui::Text(s4.c_str());
	// ImGui::End();
}

void Player::draw()
{
	Entity::draw();

#pragma region // Print si on collisionne DEPRECATED, NE PRINTERA JAMAIS TRUE
	{
		std::string mario = "Colliding: ";
		mario += std::to_string(colliding);
		// App::Print(Pos.x - 50, Pos.y + 50, mario.c_str());
		// App::Print(Pos.x - 50, Pos.y + 100, (std::to_string((int)Pos.x) + " " + std::to_string((int)Pos.y)).c_str());
	}
#pragma endregion

#pragma region // Print les entit�s par ordre de distance au joueur
//{
//	std::vector<Entity*> e = EntitiesManager::GetInstance()->entities;
//	App::Print(10, 400, (std::to_string((int)e[0]->Pos.x) + " | " + std::to_string((int)e[1]->Pos.x) + " | " + std::to_string((int)e[2]->Pos.x) + " | " + std::to_string((int)e[3]->Pos.x)).c_str());
//	std::sort(e.begin(), e.end(), [this](const Entity* a, const Entity* b)
//		{
//			return a->Dist_to_player() < b->Dist_to_player();
//		});
//	App::Print(30, 300, (std::to_string((int)e[0]->Pos.x) + " | " + std::to_string((int)e[1]->Pos.x) + " | " + std::to_string((int)e[2]->Pos.x) + " | " + std::to_string((int)e[3]->Pos.x)).c_str());
//}
#pragma endregion
}

void Player::check_collisions()
{
	std::vector<Entity *> e = EntitiesManager::GetInstance()->entities;

	std::sort(e.begin(), e.end(), [this](const Entity *a, const Entity *b)
			  { return a->Dist_to_player() < b->Dist_to_player(); });

	ImGui::Begin("Player");
	std::string s;
	s = "Colliding = ";
	std::string s1 = "False";
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i] == this)
			continue;
		if (collided_with(*e[i]))
		{
			resolve_collision(*e[i]);
			i--;
			s1 = "True";
		}
	}
	ImGui::Text((s + s1).c_str());
	ImGui::End();
}

bool Player::collided_with(const Entity &entity)
{
	bool yesh =
		this->velocity_.x + this->Pos.x - this->Colbox.x<entity.Pos.x + entity.Colbox.x &&this->velocity_.x + this->Pos.x + this->Colbox.x> entity.Pos.x - entity.Colbox.x;
	bool yesv =
		this->velocity_.y + this->Pos.y - this->Colbox.y<entity.Pos.y + entity.Colbox.y &&this->velocity_.y + this->Pos.y + this->Colbox.y> entity.Pos.y - entity.Colbox.y;

	colliding = (yesh && yesv);
	return colliding;
}

void Player::resolve_collision(const Entity &entity)
{
	vec2 diff = (this->Pos - entity.Pos);
	vec2 dir = diff.normalized();
	vec2 dir2;
	if (abs(dir.x) > abs(dir.y))
	{
		dir2 = {dir.x, 0};
		this->velocity_.x = 0.0f;
		float posToSnap = entity.Colbox.x + this->Colbox.x;
		if (this->Pos.x < entity.Pos.x)
			posToSnap *= -1;
		this->Pos.x = entity.Pos.x + posToSnap;
	}
	else
	{
		dir2 = {0, dir.y};
		this->velocity_.y = 0.0f;
		float posToSnap = entity.Colbox.y + this->Colbox.y;
		if (this->Pos.y < entity.Pos.y)
			posToSnap *= -1;
		this->Pos.y = entity.Pos.y + posToSnap;
	}
}

void Player::AddGravity(float delta)
{
}