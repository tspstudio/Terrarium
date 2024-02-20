#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "window.hpp"
#include "text.hpp"

int main()
{
    Window win(800,600,"Terrarium");

    sf::Text text1 = text(50,50,"Terrarium", 24, win.font, sf::Color::White);

    while (win.window.isOpen())
    {
        
        sf::Event event;
        while (win.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) win.window.close();
        }

        
        win.window.clear(sf::Color::Black);

        win.window.draw(text1);

        win.window.display();
    }
    return 0;
}