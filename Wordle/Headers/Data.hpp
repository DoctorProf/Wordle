#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

namespace texture
{
    extern std::vector<Texture> letters;

    extern Texture EMPTY;
    extern Texture À;
    extern Texture Á;
    extern Texture Â;
    extern Texture Ã;
    extern Texture Ä;
    extern Texture Å;
    extern Texture Æ;
    extern Texture Ç;
    extern Texture È;
    extern Texture É;
    extern Texture Ê;
    extern Texture Ë;
    extern Texture Ì;
    extern Texture Í;
    extern Texture Î;
    extern Texture Ï;
    extern Texture Ð;
    extern Texture Ñ;
    extern Texture Ò;
    extern Texture Ó;
    extern Texture Ô;
    extern Texture Õ;
    extern Texture Ö;
    extern Texture ×;
    extern Texture Ø;
    extern Texture Ù;
    extern Texture Ú;
    extern Texture Û;
    extern Texture Ü;
    extern Texture Ý;
    extern Texture Þ;
    extern Texture ß;

    void loadTextures();
}