#include "../include/Player.h";

Player::Player() : colour(WHITE){};

Player::Player(Colour colour) : colour(colour){};

Pair Player::selectPiece()
{
  std::string inp;
  std::getline(std::cin, inp);
  Pair selectedCoords = parseInput(inp);
  return selectedCoords;
}

int Player::selectMove()
{
  std::string inp;
  std::getline(std::cin, inp);
  return atoi(inp.c_str()) - 1;
}

Pair Player::parseInput(std::string inp)
{
  return Pair(inp[1] - '0' - 1, inp[0] - 'A');
}