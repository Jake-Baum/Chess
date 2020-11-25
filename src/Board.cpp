#include "../include/Board.h"

#include <iostream>

Board::Board()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      board[i][j] = NULL;
    }
  }
  for (int i = 0; i < 8; i++)
  {
    board[1][i] = new Pawn();
    board[6][i] = new Pawn();
  }
}

Board::~Board()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      delete board[i][j];
    }
  }
}

void Board::print()
{
  std::cout << "  ";
  for (char column = 'A'; column <= 'H'; column++)
  {
    std::cout << column << ' ';
  }
  std::cout << "\n";
  int rowNum = 1;
  for (auto &row : board)
  {
    std::cout << rowNum << '|';
    for (auto &tile : row)
    {
      std::cout << (tile != NULL ? tile->getChar() : '_') << '|';
    }
    std::cout << '\n';
    rowNum++;
  }
}

std::vector<Pair> Board::getPossibleMoves(Pair selectedCoords)
{
  int row = selectedCoords.first, column = selectedCoords.second;
  std::vector<Pair> possibleMoves;
  Piece *selected = board[row][column];

  for (int i = 0; i < selected->NUMBER_OF_MOVE_OFFSETS; i++)
  {
    Pair move = {row + selected->MOVE_OFFSETS[i].second,
                 column + selected->MOVE_OFFSETS[i].first};
    if (isPairWithinBounds(move) && board[move.first][move.second] == NULL)
    {
      possibleMoves.push_back(move);
    }
  }
  return possibleMoves;
}

bool Board::isPairWithinBounds(Pair move)
{
  return move.first >= 0 && move.first < 8 && move.second >= 0 && move.second < 8;
}

Piece **Board::operator[](int index)
{
  return board[index];
}