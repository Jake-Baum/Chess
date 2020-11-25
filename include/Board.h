#include "Pawn.h"

#include <vector>

class Board {
  private:
    Piece *board[8][8];

  public:
    Board();
    ~Board();

    static bool isPairWithinBounds(Pair move);
    
    void print();
    std::vector<Pair> getPossibleMoves(Pair);
    Piece **operator[](int);
};