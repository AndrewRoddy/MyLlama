#include <iostream>
#include <list>

using std::cout; using std::cin; using std::endl; using std::list;

char arr[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}} ;
char player = 'X';

void drawBoard() {
    cout << "\n\n\n\n\n\n\n\n\n" << endl; // Adds a ton of space to the top
    int counter = 0;
    int divider_count = 0;
    
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

        // Makes sure we do not put a divider at the bottom
        if (divider_count < 2) {
            cout << "--- --- ---" << endl;
            divider_count += 1;
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

char winCheck() {
    char check = 'X';
    for (int i = 0; i < 2; ++i) {
        for(int z = 0; z < 3; ++z) {
            if (arr[z][0] == check && arr[z][1] == check && arr[z][2] == check) {
            return check;
            }
            if (arr[0][z] == check && arr[1][z] == check && arr[2][z] == check) {
            return check;
            }
        }
        if (arr[0][0] == check && arr[1][1] == check && arr[2][2] == check) {
            return check;
        }
        if (arr[0][2] == check && arr[1][1] == check && arr[2][0] == check) {
            return check;
        }
        check = 'O';
    }
    return 'Z';
}

void restartGame() {
    arr[0][0] = '1'; arr[0][1] = '2'; arr[0][2] = '3';
    arr[1][0] = '4'; arr[1][1] = '5'; arr[1][2] = '6';
    arr[2][0] = '7'; arr[2][1] = '8'; arr[2][2] = '9';
    player = 'X';
    drawBoard();
}

main() {
    int move;
    bool running = true;
    char restart;
    drawBoard();

    while (running == true) {
        cout << "Player " << player << "'s turn: ";
        cin >> move;

        int row = getRow(move);
        int col = getCol(move);

        if (arr[row][col] != 'X' && arr[row][col] != 'O' ){        
            if (player == 'X') {
                arr[row][col] = 'X';
                player = 'O';
            } else {
                arr[row][col] = 'O';
                player = 'X';
            }

            drawBoard();
        
       } else {
        cout << "You cannot move there!" << endl;
       }

        if (winCheck() != 'Z') {
            cout << "WINNER IS " << winCheck() << "\nPlay Again? Y/N ";;
            cin >> restart;
            if (restart != 'Y') {
                running = false;
            } else {
                restartGame();
            }
        }
    }
}