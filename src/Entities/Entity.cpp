// #include "stdafx.h"
#include "entity.h"
#include "EntitiesManager.h"
// #include "App/app.h"

// Entity::Entity() :
//	sprite_()
//{
// }

void Entity::init(const vec2 &pos, const char *path)
{
	Pos = pos;
	texture_.loadFromFile(path);
	sprite_ = sf::Sprite(texture_);
	sprite_.setScale(6, 6);
	texture_.setSmooth(false);
	speed_ = 0;
}

void Entity::update(const float delta)
{
	Pos = Pos + velocity_ * delta * speed_;
	sprite_.setPosition(Pos.x, Pos.y);
	// texture_->SetPosition(Pos.x, Pos.y);
	// image_->Update(delta);
}

void Entity::draw()
{
}

vec2 Entity::snap_pos() // Unused, that sucks
{
	float m = Pos.x / 8.0f;
	m = roundf(m);
	m = 8.0f * m;
	float n = Pos.y / 8.0f;
	n = roundf(n);
	n = 8.0f * n;
	return {m, n};
}

float Entity::Dist_to_player() const
{
	return (EntitiesManager::GetInstance()->entities[0]->Pos - this->Pos).magnitude();
}
