#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>

#pragma once

typedef std::pair<int, int> Pair;

enum Colour
{
  WHITE = 'W',
  BLACK = 'B'
};

class Piece
{
private:
  std::vector<Pair> transformMoveOffsets(std::vector<Pair> moveOffsets)
  {
    std::vector<Pair> transformed;
    std::transform(moveOffsets.begin(), moveOffsets.end(), std::back_inserter(transformed), [this](Pair pair) {
      return Pair{pair.first, pair.second * (this->colour == BLACK ? -1 : 1)};
    });
    return transformed;
  }

protected:
  Piece(const Colour colour) : colour(colour){};

public:
  const Colour colour;

  virtual char getChar() = 0;
  virtual std::vector<Pair> getPossibleMoves(int = 8) = 0;
};