#ifndef MECHANICS_H
#define MECHANICS_H

#include <vector>
#include <string>

// Temporary asset references for board and pieces
struct BoardAssetRef {
    std::string boardTexture;        // Placeholder board image
    std::string tileHighlight;       // Placeholder highlight overlay
};

struct PieceAssetRef {
    std::string texture;             // Placeholder piece sprite
    std::string idleAnim;            // Placeholder idle animation
    std::string moveAnim;            // Placeholder move animation
};

// Basic piece and move enums
enum class PieceType {
    None,
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

enum class PieceColor {
    None,
    White,
    Black
};

// Move representation
struct Move {
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
};

// Individual piece using piece assets
class ChessPiece {
public:
    PieceType type;
    PieceColor color;
    PieceAssetRef assets;

    ChessPiece();
    ChessPiece(PieceType t, PieceColor c, const PieceAssetRef& a);

    bool isEmpty() const;
    bool isOpponent(const ChessPiece& other) const;
};

// Board storing pieces and board assets
class ChessBoard {
private:
    ChessPiece board[8][8];
    BoardAssetRef boardAssets;

public:
    ChessBoard();
    ChessBoard(const BoardAssetRef& assets);

    const ChessPiece& getPiece(int r, int c) const;
    void setPiece(int r, int c, const ChessPiece& p);
    bool inBounds(int r, int c) const;

    const BoardAssetRef& getBoardAssets() const;

    std::vector<Move> getLegalMoves(int row, int col) const;

private:
    void addPawnMoves(int r, int c, std::vector<Move>& out) const;
    void addRookMoves(int r, int c, std::vector<Move>& out) const;
    void addKnightMoves(int r, int c, std::vector<Move>& out) const;
    void addBishopMoves(int r, int c, std::vector<Move>& out) const;
    void addQueenMoves(int r, int c, std::vector<Move>& out) const;
    void addKingMoves(int r, int c, std::vector<Move>& out) const;
};

// Game controller
class ChessGame {
private:
    ChessBoard board;
    PieceColor turn;

public:
    ChessGame(const BoardAssetRef& boardAssets);

    const ChessBoard& getBoard() const;

    std::vector<Move> onPieceSelected(int row, int col) const;

    bool makeMove(const Move& move);
    PieceColor currentTurn() const;
};

#endif
