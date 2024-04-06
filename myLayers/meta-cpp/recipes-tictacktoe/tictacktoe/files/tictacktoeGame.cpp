/*
 *   A simple game of tic tac toe
 *   (c) Afaan Bilal
*/

#include <cstdlib>
#include <iostream>

using namespace std;

char b[9];
void allocBoard();
void printBoard();
bool checkWin(char);
void printWin(char);
bool checkDraw();
void printDraw();

char player;

int main()
{
    allocBoard();
    int ch = -1;
    player = 'X';
    while (ch != 0)
    {
        system("cls");
        cout << endl << "\t   TIC TAC TOE\t\t\t by Afaan Bilal" << endl << endl;
        printBoard();
        cout << "\n Player " << player << ": Enter a number to place your mark (0 to quit): "; cin >> ch;
        if (ch > 0 && ch < 10)
        {
            if (b[ch - 1] == (char)('0' + ch))
            {
                b[ch - 1] = player;
                if (checkWin(player))
                {
                    printWin(player);
                    break;
                }
                if (checkDraw())
                {
                    printDraw();
                    break;
                }
                player = player == 'X' ? 'O' : 'X';
            }
            else
            {
                //cout << "\nb[ch-1] = " << b[ch-1] << "  '0' + ch - 1 = " << (char)('0' + ch - 1) << endl;
                cout << "\n Place occupied.\n Enter another number between 1 and 9: "; cin >> ch;
            }
        }
        else if (ch != 0)
        {
            cout << "\n Invalid choice.\n Enter a number between 1 and 9: "; cin >> ch;
        }
    }
    
    cout << "\n\t Thank you for playing!" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    cin.get();
    return EXIT_SUCCESS;
}

void allocBoard()
{
    for (int i = 0; i < 9; i++)
        b[i] = (char)('0' + i + 1);
}

void printBoard()
{
    cout << "\t     |     |     " << endl;
    cout << "\t  " << b[0] << "  |  " << b[1] << "  |  " << b[2] << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t-----|-----|-----" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << b[3] << "  |  " << b[4] << "  |  " << b[5] << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t-----|-----|-----" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << b[6] << "  |  " << b[7] << "  |  " << b[8] << endl;
    cout << "\t     |     |     " << endl;
}

bool checkWin(char who)
{
    if (b[0] == who && b[1] == who && b[2] == who) return true;
    if (b[3] == who && b[4] == who && b[5] == who) return true;
    if (b[6] == who && b[7] == who && b[8] == who) return true;
    if (b[0] == who && b[3] == who && b[6] == who) return true;
    if (b[1] == who && b[4] == who && b[7] == who) return true;
    if (b[2] == who && b[5] == who && b[8] == who) return true;
    if (b[0] == who && b[4] == who && b[8] == who) return true;
    if (b[2] == who && b[4] == who && b[6] == who) return true;
    
    return false;
}

void printWin(char who)
{
    // Remove number marks
    for (int i = 0; i < 9; i++)
        if (b[i] == (char)('0' + i + 1))
            b[i] = ' ';

    system("cls");
    cout << endl << "\t   TIC TAC TOE\t\t\t by Afaan Bilal" << endl << endl;
    printBoard();
    cout << "\n     CONGRATULATIONS! Player " << who << " has won!" << endl;
}

bool checkDraw()
{
    for (int i = 0; i < 9; i++)
        if (b[i] == (char)('0' + i + 1))
            return false;
    
    return true;
}

void printDraw()
{
    system("cls");
    cout << endl << "\t   TIC TAC TOE\t\t\t by Afaan Bilal" << endl << endl;
    printBoard();
    cout << "\n     DRAW! It's the cat's game :P" << endl;
}