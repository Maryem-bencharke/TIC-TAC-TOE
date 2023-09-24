#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


char arr[3][3] = {{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'}};

void display_tictac()
{
    cout << "Player 1 ['X']  vs Player 2 ['O'] " << endl;
    cout << endl;

    cout << arr[0][0] << "   |   " << arr[0][1] << "|   "  << arr[0][2] << endl;
    cout << "____|____|___" << endl;
    cout << "    |    | " << endl;
    cout <<  arr[1][0] << "   |   " << arr[1][1] << "|   " << arr[1][2] << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |   " << endl;
    cout << arr[2][0] << "   |   " << arr[2][1] << "|   " << arr[2][2] << endl;
    cout << "    |    |   " << endl;
}

int checkwinner()
{
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
    {
        return 1;
    }
    else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
    {
        return 1;
    }
    else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
    {
        return 1;
    }
    else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
    {
        return 1;
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
    {
        return 1;
    }
    else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
    {
        return 1;
    }
    else if (arr[0][1] == arr[1][1] && arr[1][0] == arr[2][1])
    {
        return 1;
    }
    else if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2])
    {
        return 1;
    }
    else if (arr[0][0]!= '1' && arr[0][1] != '2' && arr[0][2] != '3'
        && arr[1][0] != '4' && arr[1][1] != '5' && arr[1][2] != '6'
        && arr[0][2] != '7' && arr[2][1] != '8' && arr[2][2] != '9')

        return 0;
    else
        return -1;
}


int main()
{
    int player = 1, i, choice;
    char mark;
    do {
        display_tictac();

        /*if (player % 2 == 0) {
            player = 1;
        }
        else {
            player = 2;
        }*/

        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << "  choose a number:  " << endl;
        cin >> choice;
        mark = (player == 1) ?  'X' : 'O';

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (arr[row][col] == choice + '0') { // '0': This is the character zero (not the integer zero).
                    //In C++, characters are represented by their ASCII values. The ASCII value of the character '0' is 48.
                    arr[row][col] = mark;
                }
            }
        }      
        
        i = checkwinner();
        player++;
    } while (i == -1);

    display_tictac();

    if (i == 1)
    {
        cout << "Player " << --player << "is the WINNER!";
    }
    else
    {
        cout << "No one wins";
    }
    cin.ignore();
    cin.get();
    return 0;


    
}
