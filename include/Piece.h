#include <utility>

typedef std::pair<int, int> Pair;

class Piece {
  public:
    static const Pair MOVE_OFFSETS[];
    static const int NUMBER_OF_MOVE_OFFSETS;

    virtual char getChar() = 0;
};