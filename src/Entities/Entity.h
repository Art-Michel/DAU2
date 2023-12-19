#pragma once
//#include "stdafx.h"

#include <memory>
#include <string>

//#include "App/SimpleSprite.h"
#include "core.h"

class Entity
{
public:
	Entity() = default;
	virtual void init(const vec2& pos, const char* path);
	virtual void update(float delta);
	virtual void draw();

public:
	vec2 Pos;
	vec2 Colbox = { 32,32 };
	float Dist_to_player() const;

protected:
	vec2 velocity_;
	CSimpleSprite* sprite_;
	//std::unique_ptr<CSimpleSprite> sprite_;
	float speed_;
	vec2 snap_pos();
};
