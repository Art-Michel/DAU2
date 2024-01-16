#include "TextManager.h"

TextManager *TextManager::GetInstance()
{
    if (instance == nullptr)
        instance = new TextManager();
    return instance;
}