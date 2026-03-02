Okay, I'm ready. Please provide the sentences. once

#include <SFML/Graphics.hpp>

/**
 * @brief Represents a single chess piece on the board.
 *
 * This class stores:
 * - Which type of piece it is (king, queen, rook, etc.)
 * - Which colour it belongs to (white/black)
 * - Its current board coordinate (e.g. {0,0} = A1)
 * - A sprite used to draw it to the window
 */

/// All piece types used in the game.
enum class PieceType
{
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn,
    None
};

/// Piece colour (side) in the game.
enum class PieceColor
{
    White,
    Black,
    None
};

class Piece
{
public:
    /// Default constructor creates an "empty" piece.
    Piece();

    /**
     * @brief Construct a piece with the given properties.
     * @param type Type of the piece (king, queen, etc.)
     * @param color Colour of the piece (white/black).
     * @param texture Texture containing the piece graphic.
     * @param boardPosition Integer board coordinate (e.g. {0,0} = A1).
     */
    Piece(PieceType type,
          PieceColor color,
          const sf::Texture& texture,
          const sf::Vector2i& boardPosition);

    /// Draw the piece onto the given window.
    void draw(sf::RenderWindow& window) const;

    /// Set the piece's logical board position (0–7, 0–7).
    void setBoardPosition(const sf::Vector2i& boardPos);

    /// Get the piece's logical board position.
    sf::Vector2i getBoardPosition() const;

    /// Move the sprite to a pixel position (usually derived from boardPos * tileSize).
    void setSpritePosition(const sf::Vector2f& pixelPos);

    /// Getters for type & colour.
    PieceType getType() const;
    PieceColor getColor() const;

    /// Mark piece as captured or not.
    void setCaptured(bool captured);
    bool isCaptured() const;

private:
    PieceType    m_type;
    PieceColor   m_color;
    bool         m_captured{ false };

    sf::Sprite   m_sprite;        ///< SFML sprite used to render the piece.
    sf::Vector2i m_boardPosition; ///< (file, rank) on the 8x8 board.
};
