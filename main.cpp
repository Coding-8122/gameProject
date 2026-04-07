#include <SFML/Graphics.hpp>
#include "piece.h"
#include "MechanicsHeader.h"
#include "button.h"
 
int main() {

    int column;
    int row;
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Chess");
    sf::RectangleShape tile(sf::Vector2f(100.f, 100.f));
    sf::Texture texture;
     texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_pawn_1x.png"); 

    Piece black_pawn;
    Piece white_pawn;

    white_pawn.setTexture(texture);
    black_pawn.setTexture(texture);
    black_pawn.setBoardPosition(sf ::Vector2i(0,1));    

    while (window.isOpen()) {
        sf::Event event;
       
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
            
        window.clear();
        for (row = 0; row <= 7; row++) {
            for (column = 0; column <= 7; column++) {
                if ((row + column) % 2 == 0) {
                     tile.setFillColor(sf::Color::White);
                    } else {
                        tile.setFillColor(sf::Color::Black);
                    }

                    tile.setPosition(100.f * column, 100.f * row);
                    window.draw(tile);
             
             // if statement to ensure that pawns are placed on the correct rows of the board relative to 8x8
            if (row == 1){
                black_pawn.setBoardPosition(sf ::Vector2i(column,row)); 
                black_pawn.draw(window);
                }
            else if (row == 6){
                white_pawn.setBoardPosition(sf ::Vector2i(column,row)); 
                white_pawn.draw(window);
            }
            } 
        } 
          window.display();
    }
         
    return 0;
}
