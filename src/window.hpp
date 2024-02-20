#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Window
{
public:
    Window(int w, int h, std::string title); // Constructor declaration
    ~Window(); // Destructor declaration
    void tick();
    sf::RenderWindow window;
    sf::Font font;
};
