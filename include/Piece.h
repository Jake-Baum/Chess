#include <utility>
#include <vector>

typedef std::pair<int, int> Pair;

enum Colour { WHITE = 'W', BLACK = 'B' };

class Piece {
  public:
    const Colour COLOUR;

    Piece(Colour colour): COLOUR(colour) {};
    virtual char getChar() = 0;
    virtual std::vector<Pair> getMoveOffsets() = 0;
};