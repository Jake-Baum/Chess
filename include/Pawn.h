#include "Piece.h"

class Pawn: public Piece {
  private:
    static const char c = 'P';

  public:
    Pawn(Colour);
    virtual char getChar();
};