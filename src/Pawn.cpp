#include "../include/Pawn.h"

Pawn::Pawn(const Colour colour) : Piece(colour) {}

char Pawn::getChar()
{
  return c;
}

std::vector<Pair> Pawn::getPossibleMoves(int boardSize) {
  return std::vector<Pair>{std::make_pair(0, colour == WHITE ? 1 : -1)};
}