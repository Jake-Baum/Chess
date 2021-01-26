#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>

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
      return Pair{pair.first, pair.second * (this->COLOUR == BLACK ? -1 : 1)};
    });
    return transformed;
  }

protected:
  Piece(const Colour colour, std::vector<Pair> moveOffsets) : COLOUR(colour), MOVE_OFFSETS(transformMoveOffsets(moveOffsets)){};

public:
  const Colour COLOUR;
  const std::vector<Pair> MOVE_OFFSETS;

  // virtual ~Piece() = 0;
  virtual char getChar() = 0;
};