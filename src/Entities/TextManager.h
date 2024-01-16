#pragma once
#include <SFML/Graphics.hpp>

class TextManager
{
    TextManager() {}

public:
    static inline TextManager *instance = nullptr;
    std::vector<sf::Text *> texts;
    static TextManager *GetInstance();
};