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

    std::string inp;

    while (true)
    {
        board.print();
        std::cout << "Select piece: ";
        std::getline(std::cin, inp);
        Pair selectedCoords = parseInput(inp);
        if (Board::isPairWithinBounds(selectedCoords))
        {
            Piece *selectedPiece = board[selectedCoords.first][selectedCoords.second];
            std::cout << "You have selected: " << (selectedPiece != NULL ? selectedPiece->getChar() : '_') << std::endl;
            if (selectedPiece != NULL)
            {
                std::vector<Pair> possibleMoves = board.getPossibleMoves(selectedCoords);
                printPossibleMoves(possibleMoves);
                
                std::cout << "Select move: ";
                std::getline(std::cin, inp);

                int moveSelection = atoi(inp.c_str()) - 1;
                Pair selectedMove = possibleMoves[moveSelection];
                std::cout << "You have selected to move piece to: " << pairToString(selectedMove) << std::endl;

                board.movePiece(selectedCoords, selectedMove);
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

    int selector = 1;
    for (Pair move : possibleMoves)
    {
        std::cout << selector << ": " << pairToString(move) << std::endl;
        selector++;
    }
}