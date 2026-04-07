#include "piece.h"

Piece::Piece() {
}

    void Piece::setTexture(const sf::Texture& texture){
        m_sprite.setTexture(texture);
    
        // working out size of the texture
        sf::Vector2u size = texture.getSize();

        // working out width and height of texture
        float scaleX = 100.f / size.x;
        float scaleY = 100.f / size.y;

        m_sprite.setScale(scaleX, scaleY);
    }

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
    window.draw(m_sprite);
}

// getter which works out the coordinates of each piece on the board
 sf::Vector2i Piece::getBoardPosition() const{
    return m_boardPosition;
}

//setter to render each board piece and place on the board
 void Piece::setSpritePosition(const sf::Vector2f& pixelPos){
    m_sprite.setPosition(pixelPos);
 }

void Piece::setBoardPosition(const sf ::Vector2i& board){
    m_boardPosition = board;
  m_sprite.setPosition(board.x * 100.f,  board.y * 100.f);
}
