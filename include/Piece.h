#include <utility>
#include <vector>

typedef std::pair<int, int> Pair;

enum Colour
{
  WHITE = 'W',
  BLACK = 'B'
};

class Piece
{
protected:
  Piece(const Colour colour, const std::vector<Pair> moveOffsets) : COLOUR(colour), MOVE_OFFSETS(moveOffsets.begin(), moveOffsets.end()){};

public:
  const Colour COLOUR;
  const std::vector<Pair> MOVE_OFFSETS;

  // virtual ~Piece() = 0;
  virtual char getChar() = 0;
};