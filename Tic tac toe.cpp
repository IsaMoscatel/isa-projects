// Tic tac toe.cpp


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

//Prototype Functions
void displayBoard(char arr[][3], int size);
bool isCheckWin(char board[][3], char Z);
bool isCheckTie(char board[][3], char Z);
void updateScores(int winner);
void startGame();
void resetBoard(char board[][3]);
void showMenu(int numPlayers);
int randBetween(int min, int max);

int main()
{
    srand(time(0));
    startGame();

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    //Variables
    char currentPlayer = 'X';

    bool gameOver = false;

    int choice, row, col;
    char again;
    int rowBot, colBot;

    //counters
    int count = 0;  //count slots to recognize tie
    int points1 = 0, totalPoints1 = 0;  //count Player1 wins
    int points2 = 0, totalPoints2 = 0;//count Player2 wins
    int pointsTie = 0, totalPointsTie = 0;
    int numPlayers;
    int choiceBot;

    //Const Variables
    const int ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9; //Menu Position


    cout << "~~~~~~~~~~~~~~~~~~Welcome to Tic-Tac-Toe~~~~~~~~~~~~~~~~~~\n\n\n";


    cout << "1. Multiplayer   \t 2. Single Player \t 3. Quit \n";
    cin >> numPlayers;

    while (numPlayers < 1 || numPlayers > 3)
    {
        cout << "Invalid answer. Enter 1, 2 or 3.\n";
        cin >> numPlayers;

    }


    if (numPlayers == 1) {


        do {
            resetBoard(board);
            currentPlayer = 'X';
            count = 0;


            //Display the empty board
            displayBoard(board, 3);
            cout << endl;

            while (!isCheckWin(board, 'X') && !isCheckWin(board, 'O'))
            {

                if (currentPlayer == 'X')
                    cout << "\nPlayer 1 Turn (X)\n\n";
                else
                    cout << "\nPlayer 2 Turn (O)\n\n";

                cout << "\nChoose the position you want to occupy:\n\n";
                cin >> choice;
                cout << endl;

                //validate users input

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Position. Enter 1 - 9. \n";
                    continue;
                }

                while (choice < 1 || choice > 9)
                {
                    cout << "Invalid Position. Enter 1 - 9.\n";
                    cin >> choice;
                }


                row = (choice - 1) / 3;
                col = (choice - 1) % 3;

                //menu
                switch (choice)
                {

                case ONE:

                    if (board[0][0] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 1 << " is occupied. Try a different position.\n\n";

                    }
                    break;

                case TWO:
                    if (board[0][1] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 2 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case THREE:
                    if (board[0][2] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 3 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case FOUR:
                    if (board[1][0] == ' ')
                    {

                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 4 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case FIVE:
                    if (board[1][1] == ' ')
                    {

                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 5 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case SIX:
                    if (board[1][2] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 6 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case SEVEN:
                    if (board[2][0] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 7 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case EIGHT:
                    if (board[2][1] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;

                    }
                    else
                    {
                        cout << "Slot " << 8 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                case NINE:
                    if (board[2][2] == ' ')
                    {
                        board[row][col] = currentPlayer;
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        count++;
                    }

                    else
                    {
                        cout << "Slot " << 9 << " is occupied. Try a different position.\n\n";
                    }
                    break;

                }

                //update board
                displayBoard(board, 3);

                //if a player wins
                if (isCheckWin(board, 'X'))
                {
                    cout << "\nPlayer 1 wins! \n\n";
                    updateScores(1);
                    break;
                }

                if (isCheckWin(board, 'O'))
                {
                    cout << "\nPlayer 2 wins! \n\n";
                    updateScores(2);
                    break;
                }


                if (count == 9)
                {
                    cout << "\nIt's a tie! \n\n";
                    updateScores(0);
                    break;
                }


            }

            cout << "1. Multiplayer   \t 2. Single Player \t 3. Quit \n\n";
            cin >> numPlayers;

            while (numPlayers < 1 || numPlayers > 3)
            {
                cout << "Invalid answer. Enter 1, 2 or 3.\n";
                cin >> numPlayers;

            }


        } while (numPlayers == 1);
    }

    if (numPlayers == 2) {

        do {
            resetBoard(board);
            currentPlayer = 'X';
            count = 0;


            //Display the empty board
            displayBoard(board, 3);
            cout << endl;

            while (!isCheckWin(board, 'X') && !isCheckWin(board, 'O'))
            {

                if (currentPlayer == 'X') {
                    cout << "\nPlayer Turn (X)\n\n";

                    cout << "\nChoose the position you want to occupy:\n\n";
                    cin >> choice;
                    cout << endl;

                    //validate users input

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid Position. Enter 1 - 9. \n";
                        continue;
                    }

                    while (choice < 1 || choice > 9)
                    {
                        cout << "Invalid Position. Enter 1 - 9.\n";
                        cin >> choice;
                    }

                    row = (choice - 1) / 3;
                    col = (choice - 1) % 3;

                    //menu

                    if (board[row][col] == ' ') {
                        board[row][col] = currentPlayer;
                        currentPlayer = 'O';
                        count++;
                    }

                    else {
                        cout << "Slot is occupied. \n\n";

                        continue;
                    }
                    displayBoard(board, 3);
                }


                if (count >= 9) {            // nothing left to play
                    break;                   // will fall into your tie check right after
                }

                if (currentPlayer == 'O') {

                    cout << "\nCPU Turn (O)\n\n";

                    do {
                        choiceBot = randBetween(1, 9);
                        rowBot = (choiceBot - 1) / 3;
                        colBot = (choiceBot - 1) % 3;

                    } while (board[rowBot][colBot] != ' ');

                    board[rowBot][colBot] = currentPlayer;
                    currentPlayer = 'X';
                    count++;
                    displayBoard(board, 3);
                    cout << endl;
                }



                //if a player wins
                if (isCheckWin(board, 'X'))
                {
                    cout << "\nPlayer wins! \n\n";
                    updateScores(1);
                    break;
                }

                else if (isCheckWin(board, 'O'))
                {
                    cout << "\nCPU wins! \n\n";
                    updateScores(2);
                    break;
                }


                else if (count == 9)
                {
                    cout << "\nIt's a tie! \n\n";
                    updateScores(0);
                    break;
                }
            }
                    cout << "1. Multiplayer \t 2. Single Player \t 3. Quit \n\n";
                    cin >> numPlayers;

                    while (numPlayers < 1 || numPlayers > 3)
                    {
                        cout << "Invalid answer. Enter 1, 2 or 3.\n";
                        cin >> numPlayers;
                    }

        } while (numPlayers == 2);

    }

    return 0;
}



 void displayBoard(char arr[][3], int size) {
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < (size); col++)
            {
                cout << arr[row][col];

                if (col < (size - 1))
                    cout << " | ";

                if (col == (size - 1))
                {
                    cout << "\n";
                }
            }
            if (row < size - 1)
                cout << "--+---+--\n";
        }
    }

bool isCheckWin(char board[][3], char Z) {


    if ((board[0][0] == Z) && (board[0][1] == Z) && (board[0][2] == Z)) { //1st row
        return true;
    }

    if ((board[1][0] == Z) && (board[1][1] == Z) && (board[1][2] == Z)) { //2nd row
        return true;
    }

    if ((board[2][0] == Z) && (board[2][1] == Z) && (board[2][2] == Z)) { //3nd row
        return true;
    }



    if ((board[0][0] == Z) && (board[1][0] == Z) && (board[2][0] == Z)) { //1st col
        return true;
    }

    if ((board[0][1] == Z) && (board[1][1] == Z) && (board[2][1] == Z)) { //2nd col
        return true;
    }

    if ((board[0][2] == Z) && (board[1][2] == Z) && (board[2][2] == Z)) { //3rd col
        return true;
    }



    if ((board[0][0] == Z) && (board[1][1] == Z) && (board[2][2] == Z)) { //diagonal
        return true;
    }

    if ((board[0][2] == Z) && (board[1][1] == Z) && (board[2][0] == Z)) { //anti diagonal
        return true;
    }

    else
        return false;

}

bool isCheckTie(char board[][3], char Z) {
    bool isOccupied = true;


    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'X';
             
            }



        }
    }
    if ((board[0][0] == Z) && (board[0][1] == Z) && (board[0][2] == Z)) { //1st row

        isOccupied;


        return true;
    }
        cout << "TIE";
        return true;
    

}


void updateScores(int winner) {

    int totalPoints1 = 0, totalPoints2 = 0, totalPointsTie = 0;
    string dummy;


    //open input file
    ifstream file("Score.txt");



    if (file)
    {
        string line;
        getline(file, line);
        getline(file, line);

        string a, b, c, d;

        file >> a >> b >> c >> d >> totalPoints1;
        file >> a >> b >> c >> d >> totalPoints2;
        file >> a >> totalPointsTie;
        file.close();
    }

    else
    {
        cout << "Failed to open file." << endl; //check if file opened
    }


    if (winner == 1) {
        ++totalPoints1;
    }

    if (winner == 2) {
        ++totalPoints2;
    }

    if (winner == 0) {
        ++totalPointsTie;
    }



    //open output file
    ofstream outputFile("Score.txt");
    if (outputFile)
    {
        outputFile << "~~~~~~~~~~~~~ Points ~~~~~~~~~~~~~~~~~~\n\n";
        outputFile << "Points - Player 1: \t" << totalPoints1 << endl;
        outputFile << "Points - Player 2: \t" << totalPoints2 << endl;
        outputFile << "Tie: \t" << totalPointsTie << endl;
        outputFile.close();
    }

    else
    {
        cout << "Failed to open file." << endl; //check if file opened
    }
    


}

void startGame() {
    string start;

    cout << "Enter any character to start: \n\n";
    cin >> start;

}

void resetBoard(char board[][3]) {

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {

            board[row][col] = (board[row][col] == 'X') ? ' ' : ' ';
        }

    }
}


void showMenu(int numPlayers) {

    cout << "1. Single Player \t 2. Multiplayer \n";
    cin >> numPlayers;
}

int randBetween(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}


