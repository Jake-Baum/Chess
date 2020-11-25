#include "../include/Board.h"

#include <iostream>
#include <string>

void gameLoop();
Pair parseInput(std::string);
std::string pairToString(Pair);
void printPossibleMoves(std::vector<Pair>);

int main()
{
    gameLoop();
    return 0;
}

void gameLoop()
{
    Board board;
    board.print();

    std::string inp;

    while (true)
    {
        std::cout << "Select piece: ";
        std::getline(std::cin, inp);
        Pair selectedCoords = parseInput(inp);
        if (Board::isPairWithinBounds(selectedCoords))
        {
            Piece *selected = board[selectedCoords.first][selectedCoords.second];
            std::cout << "You have selected: " << (selected != NULL ? selected->getChar() : '_') << std::endl;
            if (selected != NULL)
            {
                std::vector<Pair> possibleMoves = board.getPossibleMoves(selectedCoords);
                printPossibleMoves(possibleMoves);
            }
        }
    }
}

Pair parseInput(std::string inp)
{
    return Pair(inp[1] - '0' - 1, inp[0] - 'A');
}

std::string pairToString(Pair pair)
{
    return "(" + std::to_string(pair.first) + ", " + std::to_string(pair.second) + ")";
}

void printPossibleMoves(std::vector<Pair> possibleMoves)
{
    std::cout << "There are " << possibleMoves.size() << " possible moves." << std::endl;
    for (Pair move : possibleMoves)
    {
        std::cout << pairToString(move) << std::endl;
    }
}