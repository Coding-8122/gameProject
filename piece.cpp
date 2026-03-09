#include "piece.h"

// getter for showing the colour of the pieces on board
PieceColor Piece::getColor() const {  
    return m_color;
}

// getter for the piece type
PieceType Piece::getType() const {
    return m_type;
}

// getter to check if a piece is captured

bool Piece::isCaptured() const{
        return m_captured;
}

//setter to update the board if a piece is captured

void Piece::setCaptured(bool captured) {
        m_captured = captured;
}

// getter to draw the board after each capture
void Piece::draw(sf::RenderWindow& window) const {
}

// setter to set the coordinates of each piece on the board
void Piece::setBoardPosition(const sf::Vector2i& boardPos) {
}

// getter which works out the coordinates of each piece on the board
 sf::Vector2i Piece::getBoardPosition() const{
}

//setter to render each board piece and place on the board
 void Piece::setSpritePosition(const sf::Vector2f& pixelPos){ 
 }




