#include "Piece.h"

class Pawn: public Piece {
  private:
    static const char c = 'P';
    static const std::vector<Pair> MOVE_OFFSETS;

  public:
    Pawn(Colour);
    // ~Pawn();
    virtual char getChar();
};