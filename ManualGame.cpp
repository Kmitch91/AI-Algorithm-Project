#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//computer interaction
int startPos; //computer will have random block chosen when going first
int aiPlacement; //where the computer will place their marker

//player interaction
int playerChoice;
bool playerTurn;

int endGame = 3; //used to determine the gamestate

//board arrays
char One = '1';
char Two = '2';
char Three = '3';
char Four = '4';
char Five = '5';
char Six = '6';
char Seven = '7';
char Eight = '8';
char Nine = '9';

int turnOne; //random variable to determine start order

int aiVictory() //conditions for computer victory
{
    if (One == 'O' && Five == 'O' && Nine == 'O' && playerTurn == false) //diagonal
        endGame = 2;
    if (Three == 'O' && Five == 'O' && Seven == 'O' && playerTurn == false) //diagonal
        endGame = 2;
    if (One == 'O' && Two == 'O' && Three == 'O' && playerTurn == false) //horizontal
        endGame = 2;
    if (Four == 'O' && Five == 'O' && Six == 'O' && playerTurn == false) //horizontal
        endGame = 2;
    if (Seven == 'O' && Eight == 'O' && Nine == 'O' && playerTurn == false) //horizontal
        endGame = 2;
    if (One == 'O' && Four == 'O' && Seven == 'O' && playerTurn == false) //vertical
        endGame = 2;
    if (Two == 'O' && Five == 'O' && Eight == 'O' && playerTurn == false) //vertical
        endGame = 2;
    if (Three == 'O' && Six == 'O' && Nine == 'O' && playerTurn == false) //vertical
        endGame = 2;
}

int playerVictory() //conditions for player victory
{
    if (One == 'X' && Five == 'X' && Nine == 'X' && playerTurn == true) //diagonal
        endGame = 1;
    if (Three == 'X' && Five == 'X' && Seven == 'X' && playerTurn == true) //diagonal
        endGame = 1;
    if (One == 'X' && Two == 'X' && Three == 'X' && playerTurn == true) //horizontal
        endGame = 1;
    if (Four == 'X' && Five == 'X' && Six == 'X' && playerTurn == true) //horizontal
        endGame = 1;
    if (Seven == 'X' && Eight == 'X' && Nine == 'X' && playerTurn == true) //horizontal
        endGame = 1;
    if (One == 'X' && Four == 'X' && Seven == 'X' && playerTurn == true) //vertical
        endGame = 1;
    if (Two == 'X' && Five == 'X' && Eight == 'X' && playerTurn == true) //vertical
        endGame = 1;
    if (Three == 'X' && Six == 'X' && Nine == 'X' && playerTurn == true) //vertical
        endGame = 1;
}

int Ai() //Ai decision maker
{
    playerTurn == false;

    if (One == 'O' && Two == 'O' && playerTurn == false && Three == '3')
    {
        Three = 'O';
        playerTurn = true;
    }

    if (Four == 'O' && Five == 'O' && playerTurn == false && Six == '6')
    {
        Six = 'O';
        playerTurn = true;
    }

    if (Seven == 'O' && Eight == 'O' && playerTurn == false && Nine == '9')
    {
        Nine = 'O';
        playerTurn = true;
    }

    if (One == 'O' && Four == 'O' && playerTurn == false && Seven == '7')
    {
        Seven = 'O';
        playerTurn = true;
    }

    if (Two == 'O' && Five == 'O' && playerTurn == false && Eight == '8')
    {
        Eight = 'O';
        playerTurn = true;
    }

    if (Three == 'O' && Six == 'O' && playerTurn == false && Nine == '9')
    {
        Nine = 'O';
        playerTurn = true;
    }

    if (One == 'O' && Five == 'O' && playerTurn == false && Nine == '9')
    {
        Nine = 'O';
        playerTurn = true;
    }

    if (Three == 'O' && Five == 'O' && playerTurn == false && Seven == '7')
    {
        Seven = 'O';
        playerTurn == true;
    }

    if ((playerChoice == 1 || playerChoice == 5 || playerChoice == 9) && playerTurn == false) {
        if ((One == 'X' && Five == 'X') && playerTurn == false && Nine == '9') //diagonal
        {
            Nine = 'O';
            playerTurn = true;
        }

        if ((One == 'X' && Nine == 'X') && playerTurn == false && Five == '5') //diagonal
        {
            Five = 'O';
            playerTurn = true;
        }

        if ((Five == 'X' && Nine == 'X') && playerTurn == false && One == '1') //diagonal
        {
            One = 'O';
            playerTurn = true;
        }
    }

    if ((playerChoice == 3 || playerChoice == 5 || playerChoice == 7) && playerTurn == false) {
        if ((Seven == 'X' && Five == 'X') && playerTurn == false && Three == '3') //diagonal
        {
            Three = 'O';
            playerTurn = true;
        }

        if ((Seven == 'X' && Three == 'X') && playerTurn == false && Five == '5') //diagonal
        {
            Five = 'O';
            playerTurn = true;
        }

        if ((Five == 'X' && Three == 'X') && playerTurn == false && Seven == '7') //diagonal
        {
            Seven = 'O';
            playerTurn = true;
        }
    }

    if ((playerChoice == 1 || playerChoice == 2 || playerChoice == 3) && playerTurn == false) {
        if ((One == 'X' && Two == 'X') && playerTurn == false && Three == '3') //horizontal row 1
        {
            Three = 'O';
            playerTurn = true;
        }

        if ((One == 'X' && Three == 'X') && playerTurn == false && Two == '2') //horizontal row 1
        {
            Two = 'O';
            playerTurn = true;
        }

        if ((Two == 'X' && Three == 'X') && playerTurn == false && One == '1') //horizontal row 1
        {
            One = 'O';
            playerTurn = true;
        }
    }

    if ((playerChoice == 4 || playerChoice == 5 || playerChoice == 6) && playerTurn == false) {
        if ((Four == 'X' && Five == 'X') && playerTurn == false && Six == '6') //horizontal row 2
        {
            Six = 'O';
            playerTurn = true;
        }

        if ((Four == 'X' && Six == 'X') && playerTurn == false && Five == '5') //horizontal row 2
        {
            Five = 'O';
            playerTurn = true;
        }

        if ((Five == 'X' && Six == 'X') && playerTurn == false && Four == '4') //horizontal row 2
        {
            Four = 'O';
            playerTurn = true;
        }
    }

    if ((playerChoice == 7 || playerChoice == 8 || playerChoice == 9) && playerTurn == false) {
        if ((Seven == 'X' && Eight == 'X') && playerTurn == false && Nine == '9') //horizontal row 3
        {
            Nine = 'O';
            playerTurn = true;
        }

        if ((Seven == 'X' && Nine == 'X') && playerTurn == false && Eight == '8') //horizontal row 3
        {
            Eight = 'O';
            playerTurn = true;
        }

        if ((Eight == 'X' && Nine == 'X') && playerTurn == false && Seven == '7') //horizontal row 3
        {
            Seven = 'O';
            playerTurn = true;
        }
    }

    if ((playerChoice == 1 || playerChoice == 4 || playerChoice == 7) && playerTurn == false) {
        if ((One == 'X' && Four == 'X') && playerTurn == false && Seven == '7') //vertical col 1
        {
            Seven = 'O';
            playerTurn = true;
        }

        if ((One == 'X' && Seven == 'X') && playerTurn == false && Four == '4') //vertical col 1
        {
            Four = 'O';
            playerTurn = true;
        }

        if ((Four == 'X' && Seven == 'X') && playerTurn == false && One == '1') //vertical col 1
        {
            One = 'O';
            playerTurn = true;
        }

    }

    if ((playerChoice == 2 || playerChoice == 5 || playerChoice == 8) && playerTurn == false) {
        if ((Two == 'X' && Five == 'X') && playerTurn == false && Eight == '8') //vertical col 2
        {
            Eight = 'O';
            playerTurn = true;
        }

        if ((Two == 'X' && Eight == 'X') && playerTurn == false && Five == '5') //vertical col 2
        {
            Five = 'O';
            playerTurn = true;
        }

        if ((Five == 'X' && Eight == 'X') && playerTurn == false && Two == '2') //vertical col 2
        {
            Two = 'O';
            playerTurn = true;
        }
    }

    if ((playerChoice == 3 || playerChoice == 6 || playerChoice == 9) && playerTurn == false) {
        if ((Three == 'X' && Six == 'X') && playerTurn == false && Nine == '9') //vertical col 3
        {
            Nine = 'O';
            playerTurn = true;
        }

        if ((Three == 'X' && Nine == 'X') && playerTurn == false && Six == '6') //vertical col 3
        {
            Six = 'O';
            playerTurn = true;
        }

        if ((Six == 'X' && Nine == 'X') && playerTurn == false && Three == '3') //vertical col 3
        {
            Three = 'O';
            playerTurn = true;
        }
    } else {
        do {

            if (One == '1' && playerTurn == false) {
                playerTurn = true;
                One = 'O';
            }
            if (Two == '2' && playerTurn == false) {
                playerTurn = true;
                Two = 'O';
            }
            if (Three == '3' && playerTurn == false) {
                playerTurn = true;
                Three = 'O';
            }
            if (Four == '4' && playerTurn == false) {
                playerTurn = true;
                Four = 'O';
            }
            if (Five == '5' && playerTurn == false) {
                playerTurn = true;
                Five = 'O';
            }
            if (Six == '6' && playerTurn == false) {
                playerTurn = true;
                Six = 'O';
            }
            if (Seven == '7' && playerTurn == false) {
                playerTurn = true;
                Seven = 'O';
            }
            if (Eight == '8' && playerTurn == false) {
                playerTurn = true;
                Eight = 'O';
            }
            if (Nine == '9' && playerTurn == false) {
                playerTurn = true;
                Nine = 'O';
            }
        } while (playerTurn = false);
    }
    return 0;
}


void gameBoard() {
    cout << "+-----+-----+-----+" << endl;
    cout << "|  " << One << "  |  " << Two << "  |  " << Three << "  |" << endl;
    cout << "+-----+-----+-----+" << endl;
    cout << "|  " << Four << "  |  " << Five << "  |  " << Six << "  |" << endl;
    cout << "+-----+-----+-----+" << endl;
    cout << "|  " << Seven << "  |  " << Eight << "  |  " << Nine << "  |\n";
    cout << "+-----+-----+-----+" << endl;
}

int playerInput() {
    if (playerChoice == 1 && One == '1')
        One = 'X';
    if (playerChoice == 2 && Two == '2')
        Two = 'X';
    if (playerChoice == 3 && Three == '3')
        Three = 'X';
    if (playerChoice == 4 && Four == '4')
        Four = 'X';
    if (playerChoice == 5 && Five == '5')
        Five = 'X';
    if (playerChoice == 6 && Six == '6')
        Six = 'X';
    if (playerChoice == 7 && Seven == '7')
        Seven = 'X';
    if (playerChoice == 8 && Eight == '8')
        Eight = 'X';
    if (playerChoice == 9 && Nine == '9')
        Nine = 'X';


    return 0;
}

int aiInput() {
    if (aiPlacement == 1 && One == '1')
        One = 'O';
    if (aiPlacement == 2 && Two == '2')
        Two = 'O';
    if (aiPlacement == 3 && Three == '3')
        Three = 'O';
    if (aiPlacement == 4 && Four == '4')
        Four = 'O';
    if (aiPlacement == 5 && Five == '5')
        Five = 'O';
    if (aiPlacement == 6 && Six == '6')
        Six = 'O';
    if (aiPlacement == 7 && Seven == '7')
        Seven = 'O';
    if (aiPlacement == 8 && Eight == '8')
        Eight = 'O';
    if (aiPlacement == 9 && Nine == '9')
        Nine = 'O';

    return 0;
}

int checkTie() {
    if (One != '1' && Two != '2' && Three != '3' && Four != '4' && Five != '5'
        && Six != '6' && Seven != '7' && Eight != '8' && Nine != '9') {
        endGame = 0;
    }

}


int main() {
    //randomize so games will not repeat same steps
    srand(time(0));

    int newGame = 1;

    int playerScore = 0;
    int aiScore = 0;
    int ties = 0;

    while (newGame == 1) {

        system("CLS");
        turnOne = rand() % (2 - 1 + 1) + 1;//generates starting person.
        startPos = rand() % (9 - 1 + 1) + 1;//computer first pick - random
        endGame = 3;
        One = '1';
        Two = '2';
        Three = '3';
        Four = '4';
        Five = '5';
        Six = '6';
        Seven = '7';
        Eight = '8';
        Nine = '9';

        cout << "Player: " << playerScore << "\n" << " Ai: " << aiScore << "\n" << " Ties: " << ties << endl;

        if (turnOne == 1)//player first
        {
            cout << "Player goes first" <<endl;
            cout << "Please choose a grid to place (X): " << endl << endl;
            gameBoard();//Gameboard
            while (!(cin >> playerChoice)) {
                cout << endl;
                cout << "Numbers only." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            playerInput();
            system("CLS");
            gameBoard();
            playerTurn = false; //switches to computer
        }

        if (turnOne == 2)//computer first
        {
            cout << "Ai goes first" << endl;
            startPos;
            aiPlacement = startPos;
            aiInput();
            cout << "The computer is choosing...\n" << endl;
            playerTurn = true; //switch to player
            gameBoard();
        }


        do {
            if (playerTurn == true) //player loop
            {
                cout << "Please choose a grid to place (X): " << endl << endl;
                while (!(cin >> playerChoice)) {
                    cout << endl;
                    cout << "Numbers only." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                playerInput();
                playerVictory();
                checkTie();
                playerTurn = false;
            }

            if (playerTurn == false) //computer loop
            {
                Ai();
                system("CLS");
                gameBoard();
                aiVictory();
                checkTie();
                playerTurn = true;
            }

        } while (endGame > 2);

        if (endGame == 0) {
            cout << "The game is a tie" << endl;
            ++ties;
        }


        if (endGame == 1) {
            cout << "The player wins" << endl;
            ++playerScore;
        }

        if (endGame == 2) {
            cout << "The ai wins" << endl;
            ++aiScore;
        }

        cout << "Player: " << playerScore << "\n" << " Ai: " << aiScore << "\n" << " Ties: " << ties << endl;

       while (!(cin >> newGame)) {
            cout << endl;
            cout << "New game? \n.1 = Yes \n.2 = No" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    while(newGame == 1);

    return 0;
}