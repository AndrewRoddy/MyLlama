#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

char arr[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}} ;

void drawBoard() {
    cout << "\n\n\n\n\n\n\n\n\n" << endl; // Adds a ton of space to the top
    int counter = 0;
    int rcount = 0;
    for (int r = 0; r < 3; r++) { // Renders all of the rows
        counter = 0;
        for (int c = 0; c < 3; c++) { // Iterates through the rows
            cout << " " << arr[r][c];
            if (counter < 2) {
                cout << " |";
                counter = counter + 1;
            }
        }
        cout << endl;
        if (rcount < 2) {
            cout << "--- --- ---" << endl;
            rcount = rcount + 1;
        }
    }
}

int getRow(int player) {
    int row = 0;
    if (player == 1 || player == 2 || player == 3) {row = 0;}
    if (player == 4 || player == 5 || player == 6) {row = 1;}
    if (player == 7 || player == 8 || player == 9) {row = 2;}
    return row;
}

int getCol(int player) {
    int column = 0;
    if (player == 1 || player == 4 || player == 7) {column = 0;}
    if (player == 2 || player == 5 || player == 8) {column = 1;}
    if (player == 3 || player == 6 || player == 9) {column = 2;}
    return column;
}

main() {
    char player = 'X';
    int move;
    while (move != 9) {
        drawBoard();
        cout << "Player " << player << "'s turn: ";
        cin >> move;

        int row = getRow(move);
        int col = getCol(move);
        
        if (arr[row][col] == ' '){        
            if (player == 'X') {
                arr[row][col] = 'X';
                player = 'O';
            } else {
                arr[row][col] = 'O';
                player = 'X';
            }
       }
    }
    

}