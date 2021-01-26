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

    Colour whoseTurn = WHITE;

    while (true)
    {
        board.print();
        std::cout << "Select piece (" << (char)whoseTurn << "): ";
        std::getline(std::cin, inp);
        Pair selectedCoords = parseInput(inp);
        if (Board::isPairWithinBounds(selectedCoords))
        {
            Piece *selectedPiece = board[selectedCoords.first][selectedCoords.second];
            if (selectedPiece != NULL && selectedPiece->COLOUR == whoseTurn)
            {
                std::cout << "You have selected: " << selectedPiece->getChar() << std::endl;

                std::vector<Pair> possibleMoves = board.getPossibleMoves(selectedCoords);
                printPossibleMoves(possibleMoves);

                if (!possibleMoves.empty())
                {
                    std::cout << "Select move: ";
                    std::getline(std::cin, inp);

                    int moveSelection = atoi(inp.c_str()) - 1;
                    Pair selectedMove = possibleMoves[moveSelection];
                    std::cout << "You have selected to move piece to: " << pairToString(selectedMove) << std::endl;

                    board.movePiece(selectedCoords, selectedMove);

                    whoseTurn = whoseTurn == WHITE ? BLACK : WHITE;
                }
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