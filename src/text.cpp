#include "text.hpp"

sf::Text text(int x, int y, std::string text, int size, sf::Font font, sf::Color color)
{
    sf::Text _text;
    _text.setFont(font);
    _text.setString(text);
    _text.setCharacterSize(size);
    _text.setFillColor(color);
    _text.setPosition(x,y);

    return _text;
}