#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

namespace data
{
    extern Font font;

    void loadFont();

    void setStyleText(Text& text, int size);
}