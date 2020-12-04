#include "../include/Pawn.h"

const Pair Pawn::MOVE_OFFSETS[] = {{0, 1}};
const int Pawn::NUMBER_OF_MOVE_OFFSETS = 1;

Pawn::Pawn(Colour colour): Piece(colour) {}

char Pawn::getChar() {
  return c;
}