#include <SFML/Graphics.hpp>
#include "core.h"

class Background
{
public:
    Background() = default;
    void Init(const vec2 &pos, const char *path, const vec2 &velocity);
    void update(float delta);

public:
    sf::Sprite sprite_;

protected:
    vec2 Velocity;
    sf::Texture texture_;
    vec2 Pos;
};