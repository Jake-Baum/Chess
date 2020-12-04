#include "Piece.h"

class Pawn: public Piece {
  private:
    static const char c = 'P';
    static const Pair MOVE_OFFSETS[];

  public:
    Pawn(Colour);
    virtual char getChar();
    virtual std::vector<Pair> getMoveOffsets();
};