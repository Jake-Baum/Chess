#include "../include/Pawn.h"

const std::vector<Pair> Pawn::MOVE_OFFSETS{std::make_pair(0, 1)};

Pawn::Pawn(const Colour colour) : Piece(colour, MOVE_OFFSETS) {}

// Pawn::~Pawn() {}

char Pawn::getChar()
{
  return c;
}