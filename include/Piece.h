#include <utility>

typedef std::pair<int, int> Pair;

enum Colour { WHITE = 'W', BLACK = 'B' };

class Piece {
  public:
    static const Pair MOVE_OFFSETS[];
    static const int NUMBER_OF_MOVE_OFFSETS;
    
    const Colour COLOUR;

    Piece(Colour colour): COLOUR(colour) {};
    virtual char getChar() = 0;
};