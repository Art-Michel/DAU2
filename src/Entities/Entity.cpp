//#include "stdafx.h"
#include "entity.h"
#include "EntitiesManager.h"
//#include "App/app.h"

//Entity::Entity() :
//	sprite_()
//{
//}

void Entity::init(const vec2& pos, const char* path)
{
	Pos = pos;
	sprite_ = App::CreateSprite(path, 1, 1);
	sprite_->SetPosition(Pos.x, Pos.y);
	sprite_->SetScale(8.0f);
	speed_ = 0;
}

void Entity::update(const float delta)
{
	Pos = Pos + velocity_ * delta * speed_;
	sprite_->SetPosition(Pos.x, Pos.y);
	sprite_->Update(delta);
}

void Entity::draw()
{
	sprite_->Draw();
}

vec2 Entity::snap_pos() //Unused, that sucks
{
	float m = Pos.x / 8.0f;
	m = roundf(m);
	m = 8.0f * m;
	float n = Pos.y / 8.0f;
	n = roundf(n);
	n = 8.0f * n;
	return { m, n };
}

float Entity::Dist_to_player() const
{
	return (EntitiesManager::GetInstance()->entities[0]->Pos - this->Pos).magnitude();
}
