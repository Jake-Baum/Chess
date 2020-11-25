#include "../include/Pawn.h"

const Pair Pawn::MOVE_OFFSETS[] = {{0, 1}};
const int Pawn::NUMBER_OF_MOVE_OFFSETS = 1;

char Pawn::getChar() {
  return c;
}