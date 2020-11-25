#include "Piece.h"

class Pawn: public Piece {
  private:
    const char c = 'P';

  public:
    virtual char getChar();
};