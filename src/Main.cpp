#include "../include/Board.h"
#include "../include/Player.h"

#include <map>

void gameLoop();
void turn(Board &, Player);
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
    Colour whoseTurn = WHITE;
    std::map<Colour, Player> players;
    Player white(WHITE), black(BLACK);
    players.emplace(WHITE, Player(WHITE));
    players.emplace(BLACK, Player(BLACK));

    while (true)
    {
        turn(board, players[whoseTurn]);
        whoseTurn = whoseTurn == WHITE ? BLACK : WHITE;
    }
}

void turn(Board &board, Player player)
{
    while (true)
    {
        board.print();
        std::cout << "Select piece (" << (char)player.colour << "): ";
        Pair selectedCoords = player.selectPiece();

        if (Board::isPairWithinBounds(selectedCoords))
        {
            Piece *selectedPiece = board[selectedCoords.first][selectedCoords.second];
            if (selectedPiece != NULL && selectedPiece->colour == player.colour)
            {
                std::cout << "You have selected: " << selectedPiece->getChar() << std::endl;

                std::vector<Pair> possibleMoves = board.getPossibleMoves(selectedCoords);
                printPossibleMoves(possibleMoves);

                if (!possibleMoves.empty())
                {
                    std::cout << "Select move: ";
                    Pair selectedMove = possibleMoves[player.selectMove()];
                    std::cout << "You have selected to move piece to: " << pairToString(selectedMove) << std::endl;

                    board.movePiece(selectedCoords, selectedMove);
                    return;
                }
            }
        }
    }
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