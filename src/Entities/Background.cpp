#include "Background.h"
#include <iostream>

void Background::Init(const vec2 &pos, const char *path, const vec2 &speed)
{
    Pos = pos;
    Velocity = speed;
    if (texture_.loadFromFile(path))
    {
        sprite_ = sf::Sprite(texture_);
        sprite_.setScale(1, 1);
        texture_.setSmooth(false);
        sprite_.setColor(sf::Color(255, 255, 255, 100));
    }
}

void Background::update(float delta)
{
    // Round Velocity to a precision of .001
    Velocity.x = roundf(Velocity.x * 100) * 0.01f;
    Velocity.y = roundf(Velocity.y * 100) * 0.01f;

    Pos = Pos + Velocity * delta;
    sprite_.setPosition(Pos.x, Pos.y);
    // if (Pos.x > 256 | Pos.y > 192)
    // {
    //     Pos.x = -256;
    //     Pos.y = -192;
    //     sprite_.setPosition(Pos.x, Pos.y);
    // }
    if (Pos.x > 256)
    {
        Pos.x -= 256 * 2;
        sprite_.setPosition(Pos.x, Pos.y);
    }
    if (Pos.y > 192)
    {
        Pos.y -= 192 * 2;
        sprite_.setPosition(Pos.x, Pos.y);
    }

    // texture_->SetPosition(Pos.x, Pos.y);
    // image_->Update(delta);
}
