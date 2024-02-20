#include "window.hpp"

Window::Window(int w, int h, std::string title) : window(sf::VideoMode(w, h), title, sf::Style::Default) {
    if (!font.loadFromFile("res/fonts/alumatica-regular.ttf")) {
        std::cerr << "Error loading font!";
    }
}

Window::~Window() {};

void Window::tick()
{
    
}