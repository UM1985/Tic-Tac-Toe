#include <iostream>
using namespace std;

class Game
{
private:
    char Board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row, column;

public:
    char turn = 'X';
    bool draw = false;
    void display_board();
    void player_turn();
    bool game_over();
};

void Game::display_board()
{
    system("cls");
    cout << "\t Tick Cross Game " << endl;
    cout << "\tPlayer1[X]\n \tPlayer2[O]\n";

    cout << "\t\t     |     |     \n";
    cout << "\t\t " << Board[0][0] << "   |  " << Board[0][1] << "  |  " << Board[0][2] << endl;
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t " << Board[1][0] << "   |  " << Board[1][1] << "  |  " << Board[1][2] << endl;
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t " << Board[2][0] << "   |  " << Board[2][1] << "  |  " << Board[2][2] << endl;
    cout << "\t\t     |     |     \n";
}
void Game::player_turn()
{
    int choice;

    if (turn == 'X')
    {
        cout << "\n\t Player1 [X] turn : ";
    }
    if (turn == 'O')
    {
        cout << "\n\tPlayer2 [O] trun : ";
    }

    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        column = 0;
        break;
    case 7:
        row = 2;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "Invalid Choice \n";
        break;
    }

    if (turn == 'X')
    {
        Board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O')
    {
        Board[row][column] = 'O';
        turn = 'X';
    }
}
bool Game::game_over()
{
    // check win
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] || Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
        {
            return false;
        }
    }
    if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] || Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != 'X' && Board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}

int main()
{
    Game A;
    while (A.game_over())
    {
        A.display_board();
        A.player_turn();
        A.game_over();
    }
    A.display_board();

    if (A.turn == 'X' && !A.draw)
    {
        cout << "Player2 [O] Wins!! Congratulations\n";
    }
    else if (A.turn == 'O' && !A.draw)
    {
        cout << "Player1 [X] Wins!! Congratulations\n";
    }
    else
    {
        cout << "Game Draw!! \n";
    }

    return 0;
}
