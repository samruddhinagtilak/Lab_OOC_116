
#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the game board
void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Check whether a player has won
bool checkWinner(char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

int main()
{
    int choice;
    char player = 'X';
    int moves = 0;

    cout << "===== TIC TAC TOE GAME =====" << endl;

    while (moves < 9)
    {
        displayBoard();

        cout << "\nPlayer " << player;
        cout << ", enter position (1-9): ";
        cin >> choice;

        // Validate position
        if (choice < 1 || choice > 9)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Convert position into row and column
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check whether position is already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        // Place player's symbol
        board[row][col] = player;
        moves++;

        // Check winner
        if (checkWinner(player))
        {
            displayBoard();
            cout << "\nPlayer " << player << " wins!" << endl;
            return 0;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    // If no winner
    displayBoard();
    cout << "\nGame Draw!" << endl;

    return 0;
}
