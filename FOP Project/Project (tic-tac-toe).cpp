//Eemaan Khalid (CMS 464000) 
//TIC TAC TOE GAME for two user players

//beginning with header file 
#include <iostream> 
using namespace std;

//initializing and declaring variables
char a[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X'; //defining the first turn
int r, c; //
bool make = false;

//function to display the basic table for the game
void showTable()
{
	cout << endl;
    cout << " TIC TAC TOE GAME " << endl;
    cout << " 1st Player : X" << endl;
    cout << " 2nd Player : O" << endl;
    cout << endl;

    cout << "      |     |      " << endl;
    cout << "   " << a[0][0] << "  |  " << a[0][1] << "  |  " << a[0][2] << endl;
    cout << " _____|_____|_____ " << endl;
    cout << "      |     |      " << endl;
    cout << "   " << a[1][0] << "  |  " << a[1][1] << "  |  " << a[1][2] << endl;
    cout << " _____|_____|_____ " << endl;
    cout << "      |     |      " << endl;
    cout << "   " << a[2][0] << "  |  " << a[2][1] << "  |  " << a[2][2] << endl;
    cout << "      |     |      " << endl;
    cout << endl;
}

//function for alternate turns of the user
void turnChanging()
{
    int choice;

    if (turn == 'X')
    {
        cout << "Player 1 turn : ";
    }
    if (turn == 'O')
    {
        cout << "Player 2 turn : ";
    }
    cin >> choice;

//using switch so user can select different cells
    switch (choice)
    {
    case 1:
        r = 0;
        c = 0;
        break;

    case 2:
        r = 0;
        c = 1;
        break;

    case 3:
        r = 0;
        c = 2;
        break;

    case 4:
        r = 1;
        c = 0;
        break;

    case 5:
        r = 1;
        c = 1;
        break;

    case 6:
        r = 1;
        c = 2;
        break;

    case 7:
        r = 2;
        c = 0;
        break;

    case 8:
        r = 2;
        c = 1;
        break;

    case 9:
        r = 2;
        c = 2;
        break;

    default:
        cout << "Your choice is invalid. Please try again." << endl;
        return;
}

// Checker for already choosen cells
if (a[r][c] == 'X' || a[r][c] == 'O')
{
    cout << "Cell is already filled. Please try again." << endl;
    return;
}
    a[r][c] = turn;
    
    //Switching in alternate turns
    if (turn == 'X')
    {
        turn = 'O';
    }
    else
    {
		turn = 'X';
    }
}

    // Function to check if the game is over/ continued or draw
    bool gameOver()
    {
	char winner = ' ';
	
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][0] == a[i][2])
        winner = a[i][0];
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (a[0][i] == a[1][i] && a[0][i] == a[2][i])
        winner = a[0][i];
    }

    // Check diagonals
    if (a[0][0] == a[1][1] && a[0][0] == a[2][2])
    {
    	winner = a[0][0];
	}
    
    if (a[0][2] == a[1][1] && a[0][2] == a[2][0])
    {
    	winner = a[0][2];
	}
	 if (winner != ' ')
    {
        cout << "Player " << (winner == 'X' ? "1" : "2") << " wins!" << endl;
        return true;
    }
	
    // Check if the board is full (draw)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != 'X' && a[i][j] != 'O')
                return false;
        }
    }
    cout << "The game is a draw!" << endl;
    return true;
    }

    int main()
    {

    while (!gameOver())
    {
        showTable();
        turnChanging();
        showTable();
    }
    
    return 0;
}
