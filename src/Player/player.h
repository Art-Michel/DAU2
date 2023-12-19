#pragma once
//#include "stdafx.h"
#include "core.h"
#include "inputs.h"
#include "entity.h"
#include "FSM.h"

class Player : public Entity
{
public:
	Player();

private:
	Inputs inputs;
	bool colliding;
	FSM fsm;

public:
	void init(const vec2& pos, const char* path) override;
	void update(float delta) override;
	void draw() override;


private:
	void check_collisions();
	bool collided_with(const Entity& entity);
	void resolve_collision(const Entity& entity);
	void AddGravity(float delta);
};
