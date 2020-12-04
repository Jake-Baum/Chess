#include "../include/Pawn.h"

const Pair Pawn::MOVE_OFFSETS[] = {{0, 1}};

Pawn::Pawn(Colour colour): Piece(colour) {}

char Pawn::getChar() {
  return c;
}

std::vector<Pair> Pawn::getMoveOffsets() {
  return std::vector<Pair>(MOVE_OFFSETS, MOVE_OFFSETS + (sizeof(MOVE_OFFSETS) / sizeof(Pair)));
}