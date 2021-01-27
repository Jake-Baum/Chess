#include "Piece.h"

#include <iostream>
#include <string>

class Player
{
private:
  Pair parseInput(std::string);

public:
  const Colour colour;

  Player();
  Player(Colour colour);
  Pair selectPiece();
  int selectMove();
};