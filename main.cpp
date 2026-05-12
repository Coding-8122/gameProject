#include <SFML/Graphics.hpp>
#include "piece.h"
#include "MechanicsHeader.h"
#include "button.h"
#include "iostream"
 
int main() {

    int column;
    int row;
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Chess");
    sf::RectangleShape tile(sf::Vector2f(100.f, 100.f));
    int whiteTurn = 1;
    int blackTurn = -1;
    int startingRow = -1;
    int startingColumn = -1;
    bool isSelecting;


    
    // loading textures for each piece type and colour from the JohnPablok Chess assets
    sf::Texture b_pawn_texture, b_king_texture, b_knight_texture, b_bishop_texture, b_rook_texture, b_queen_texture;
    sf::Texture w_pawn_texture, w_king_texture, w_knight_texture, w_bishop_texture, w_rook_texture, w_queen_texture;

    b_pawn_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_pawn_1x.png");
    b_king_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_king_1x.png");
    b_knight_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_knight_1x.png");
    b_bishop_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_bishop_1x.png");
    b_rook_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_rook_1x.png");
    b_queen_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/b_queen_1x.png");

    w_pawn_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/w_pawn_1x.png");
    w_king_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/w_king_1x.png");
    w_knight_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/w_knight_1x.png");
    w_bishop_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/w_bishop_1x.png");
    w_rook_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/w_rook_1x.png");
    w_queen_texture.loadFromFile("JohnPablok Cburnett Chess set/PNGs/With Shadow/1x/w_queen_1x.png");
    
    
    Piece b_pawn, b_king, b_knight, b_bishop, b_rook, b_queen;
    Piece w_pawn, w_king, w_knight, w_bishop, w_rook, w_queen;

    b_pawn.setTexture(b_pawn_texture);   
    b_king.setTexture(b_king_texture);   
    b_knight.setTexture(b_knight_texture);   
    b_bishop.setTexture(b_bishop_texture);   
    b_rook.setTexture(b_rook_texture);   
    b_queen.setTexture(b_queen_texture);   
    
    w_pawn.setTexture(w_pawn_texture);   
    w_king.setTexture(w_king_texture);   
    w_knight.setTexture(w_knight_texture);   
    w_bishop.setTexture(w_bishop_texture);   
    w_rook.setTexture(w_rook_texture);   
    w_queen.setTexture(w_queen_texture);   
    


/* Key for board logic:
1 = Rook 2 = Knight 3 = Bishop 4 = Queen
5 = King 6 = Pawn

Positive numbers = Black pieces
Negative numbers = white pieces

*/



    int board[8][8] = {
    {1,2,3,4,5,3,2,1},
    {6,6,6,6,6,6,6,6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {-1,-2,-3,-4,-5,-3,-2,-1}
    };

    while (window.isOpen()) {
        sf::Event event;
       
        while (window.pollEvent(event)) {
            
            if(event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left){
              column = event.mouseButton.x / 100;
              row = event.mouseButton.y / 100;
            
                if(isSelecting == false && (board[row][column] !=0 )){
                        startingRow = row;
                        startingColumn = column;
                       isSelecting = true; 
                        std::cout << "The selected piece : " << board[row][column] << " at:" << startingRow  << "," << startingColumn << std::endl;
                }
                    else if (isSelecting == true){
                        board[row][column] = board[startingRow][startingColumn];
                        board[startingRow][startingColumn] = 0;
                        isSelecting = false;
                        std::cout << "The piece is moved to: " << column << "," << row << std::endl;
                        
                        }
                    }
                }
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
             
             // piece id logic which maps each piece to a number on the previously implemented map and draws on the board accordingly
            int piece_id = board [row][column];

                if (piece_id == 1){
                b_rook.setBoardPosition(sf ::Vector2i(column,row)); 
                b_rook.draw(window);
                }

                 if (piece_id == 2){
                b_knight.setBoardPosition(sf ::Vector2i(column,row)); 
                b_knight.draw(window);
                }
                 if (piece_id == 3){
                b_bishop.setBoardPosition(sf ::Vector2i(column,row)); 
                b_bishop.draw(window);
                }
                 if (piece_id == 4){
                b_queen.setBoardPosition(sf ::Vector2i(column,row)); 
                b_queen.draw(window);
                }
                 if (piece_id == 5){
                b_king.setBoardPosition(sf ::Vector2i(column,row)); 
                b_king.draw(window);
                }
                 if (piece_id == 6){
                b_pawn.setBoardPosition(sf ::Vector2i(column,row)); 
                b_pawn.draw(window);
                }
               
                
             if (piece_id == -1){
                w_rook.setBoardPosition(sf ::Vector2i(column,row)); 
                w_rook.draw(window);
                }

                 if (piece_id == -2){
                w_knight.setBoardPosition(sf ::Vector2i(column,row)); 
                w_knight.draw(window);
                }
                 if (piece_id == -3){
                w_bishop.setBoardPosition(sf ::Vector2i(column,row)); 
                w_bishop.draw(window);
                }
                 if (piece_id == -4){
                w_queen.setBoardPosition(sf ::Vector2i(column,row)); 
                w_queen.draw(window);
                }
                 if (piece_id == -5){
                w_king.setBoardPosition(sf ::Vector2i(column,row)); 
                w_king.draw(window);
                }
                 if (piece_id == -6){
                w_pawn.setBoardPosition(sf ::Vector2i(column,row)); 
                w_pawn.draw(window);
                }
            }
            }  
          window.display();
    }
         
    return 0;
}
