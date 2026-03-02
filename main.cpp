#include <SFML/Graphics.hpp>
#include "piece.h"
#include "MechanicsHeader.h"
#include "button.h"
 
int main() {

    int column;
    int row;
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Chess");
    sf::RectangleShape tile(sf::Vector2f(100.f, 100.f));


    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            window.clear();

            for (row = 0; row <= 7; row++) {
                for (column = 0; column <= 7; column++) {
                    if ((row + column) % 2 == 0) {
                        tile.setFillColor(sf::Color::White);

                    }
                    else {
                        tile.setFillColor(sf::Color::Black);
                    }

                    tile.setPosition(100.f * column, 100.f * row);
                    window.draw(tile);
                }
            }

            window.display();
        }
    }
    return 0;
}
