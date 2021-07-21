#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::make_pair;
using std::vector;
using std::pair;
using std::find;
using std::end;
using std::begin;
using std::min;
using std::max;

#define WIN 1000
#define	TIE 0
#define LOSS -1000

#define CPU 'O'
#define USER 'X'
#define BLANK '*'

#define DEPTH 0

// print the result of the game
void GameStatePrint(int state)
{
    if (WIN == state) {
        cout << "WIN" << endl;
    }
    else if (TIE == state) {
        cout << "TIE" << endl;
    }
    else if (LOSS == state) {
        cout << "LOSS" << endl;
    }
}

// create all possible ways to win
vector<vector<pair<int, int>>> WinStates
        {
                { make_pair(0, 0), make_pair(0, 1), make_pair(0, 2) }, // row 0
                { make_pair(1, 0), make_pair(1, 1), make_pair(1, 2) }, // row 1
                { make_pair(2, 0), make_pair(2, 1), make_pair(2, 2) }, // row 2
                { make_pair(0, 0), make_pair(1, 0), make_pair(2, 0) }, //  column 0
                { make_pair(0, 1), make_pair(1, 1), make_pair(2, 1) }, // column 1
                { make_pair(0, 2), make_pair(1, 2), make_pair(2, 2) }, // column 2
                { make_pair(0, 0), make_pair(1, 1), make_pair(2, 2) }, // diagonal from top right
                { make_pair(2, 0), make_pair(1, 1), make_pair(0, 2) }  // diagonal from bottom right

        };

// Print the current board state
void PrintBoard(char board[3][3])
{
    cout << endl;
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "_" << " + " <<"_"<< " + "<< "_" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "_" << " + " <<"_"<< " + "<< "_" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl << endl;
}

// Get all available legal moves (spaces that are not occupied)
vector<pair<int, int>> GetLegalMoves(char board[3][3])
{
    vector<pair<int, int>> legalmoves;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != CPU && board[i][j] != USER)
            {
                legalmoves.push_back(make_pair(i, j));
            }
        }
    }

    return legalmoves;
}

// Check if a position is occupied
bool SpaceTaken(char board[3][3], pair<int, int> pos)
{
    vector<pair<int, int>> legalmoves = GetLegalMoves(board);

    for (int i = 0; i < legalmoves.size(); i++)
    {
        if (pos.first == legalmoves[i].first && pos.second == legalmoves[i].second)
        {
            return false;
        }
    }

    return true;
}

// Get all board positions occupied by the given marker
vector<pair<int, int>> GetSpaceTaken(char board[3][3], char symbol)
{
    vector<pair<int, int>> SpaceTaken;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (symbol == board[i][j])
            {
                SpaceTaken.push_back(make_pair(i, j));
            }
        }
    }

    return SpaceTaken;
}

// Check if the board is full
bool Full(char board[3][3])
{
    vector<pair<int, int>> legalmoves = GetLegalMoves(board);

    if (0 == legalmoves.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check if the game has been won
bool moveHaswon(vector<pair<int, int>> SpaceTaken)
{
    bool haswon;

    for (int i = 0; i < WinStates.size(); i++)
    {
        haswon = true;
        vector<pair<int, int>> current = WinStates[i];
        for (int j = 0; j < 3; j++)
        {
            if (!(find(begin(SpaceTaken), end(SpaceTaken), current[j]) != end(SpaceTaken)))
            {
                haswon = false;
                break;
            }
        }

        if (haswon)
        {
            break;
        }
    }
    return haswon;
}

char GetOpposing(char symbol)
{
    char OopSymbol;
    if (symbol == USER)
    {
        OopSymbol = CPU;
    }
    else
    {
        OopSymbol = USER;
    }

    return OopSymbol;
}

// Check if someone has won or lost
int GetBoardState(char board[3][3], char symbol)
{

    char OopSymbol = GetOpposing(symbol);

    vector<pair<int, int>> SpaceTaken = GetSpaceTaken(board, symbol);

    bool is_won = moveHaswon(SpaceTaken);

    if (is_won)
    {
        return WIN;
    }

    SpaceTaken = GetSpaceTaken(board, OopSymbol);
    bool is_lost = moveHaswon(SpaceTaken);

    if (is_lost)
    {
        return LOSS;
    }

    bool is_full = Full(board);
    if (is_full)
    {
        return TIE;
    }

    return TIE;

}

// Apply the minimax game optimization algorithm
pair<int, pair<int, int>> MiniMax(char board[3][3], char symbol, int depth, int alpha, int beta)
{
    // Initialize best move
    pair<int, int> BestMove = make_pair(-1, -1);
    int BestScore = (symbol == CPU) ? LOSS : WIN;

    // If we hit a terminal state (leaf node), return the best score and move
    if (Full(board) || TIE != GetBoardState(board, CPU) || depth == 8)
    {
        BestScore = GetBoardState(board, CPU);
        return make_pair(BestScore, BestMove);
    }

    vector<pair<int, int>> legalmoves = GetLegalMoves(board);

    for (int i = 0; i < legalmoves.size(); i++)
    {
        pair<int, int> curr_move = legalmoves[i];
        board[curr_move.first][curr_move.second] = symbol;

        // Maximizing player's turn
        if (symbol == CPU)
        {
            int score = MiniMax(board, USER, depth + 1, alpha, beta).first;

            // Get the best scoring move
            if (BestScore < score)
            {
                BestScore = score - depth * 10;
                BestMove = curr_move;

                // Check if this branch's best move is worse than the best
                // option of a previously search branch. If it is, skip it
                alpha = max(alpha, BestScore);
                board[curr_move.first][curr_move.second] = BLANK;
                if (beta <= alpha)
                {
                    break;
                }
            }

        } // Minimizing opponent's turn
        else
        {
            int score = MiniMax(board, CPU, depth + 1, alpha, beta).first;

            if (BestScore > score)
            {
                BestScore = score + depth * 10;
                BestMove = curr_move;

                // Check if this branch's best move is worse than the best
                // option of a previously search branch. If it is, skip it
                beta = min(beta, BestScore);
                board[curr_move.first][curr_move.second] = BLANK;
                if (beta <= alpha)
                {
                    break;
                }
            }

        }

        board[curr_move.first][curr_move.second] = BLANK; // Undo move

    }

    return make_pair(BestScore, BestMove);
}

// Check if the game is finished
bool GameOver(char board[3][3])
{
    if (Full(board))
    {
        return true;
    }

    if (TIE != GetBoardState(board, CPU))
    {
        return true;
    }

    return false;
}


int main()
{



    char board [3][3] = {BLANK};
    cout<<"Select spot by inputting row and column that desired spot matches board template"<<endl;
    cout<<endl;
    cout<<"(0,0) | (0,1) | (0,2)"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"(1,0) | (1,1) | (1,2)"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"(2,0) | (2,1) | (2,2)"<<endl;

    PrintBoard(board);





            srand(time(NULL));
            int random1 = rand() % 3;
            int random2 = rand() & 3;
            board[random1][random2] = USER;

            cout << "Random x move: " << endl;
            PrintBoard(board);


            pair<int, pair<int, int>> ai_move = MiniMax(board, CPU, DEPTH, LOSS, WIN);

            board[ai_move.second.first][ai_move.second.second] = CPU;


            cout << "O Ai Move: " << endl;
            PrintBoard(board);


            while (!GameOver(board)) {
                /*int row;
                int column;
                cout << "Play index of row of spot you like to place symbol at: ";
                cin >> row;
                cout << "play index of column of spot you like to place symbol at: ";
                cin >> column;
                cout << endl << endl;

                if (SpaceTaken(board, make_pair(row, column)))
                {
                    cout << "(" << row << ", " << column << ") is an invalid entry! Try a new coordinate" << endl;
                    continue;
                }
                else
                {
                    board[row][column] = USER;
                }*/

                cout << "Moves made: " << endl;

                pair<int, pair<int, int>> user_move = MiniMax(board, USER, DEPTH, LOSS, WIN);
                board[user_move.second.first][user_move.second.second] = USER;

                pair<int, pair<int, int>> ai_move = MiniMax(board, CPU, DEPTH, LOSS, WIN);

                board[ai_move.second.first][ai_move.second.second] = CPU;

                // pair<int, pair<int,int>> user_move = MiniMax(board, USER, DEPTH, LOSS, WIN);
                // board[user_move.second.first][user_move.second.second] = USER;

                PrintBoard(board);
            }


            int player_state = GetBoardState(board, USER);

            GameStatePrint(player_state);



            return 0;


}