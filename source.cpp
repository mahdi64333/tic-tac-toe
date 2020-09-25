#include <iostream>

using namespace std;

int freeCell, mainBoard[3][3];

void pause() {
    cout << "\nPress enter...";
    cin.ignore().get();
}

void init(int board[3][3]) {
    system("clear"); //Use system("cls") for windows os
    freeCell = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
}

void draw(int board[3][3]) {
    system("clear"); //Use system("cls") for windows os
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(board[i][j] == 0) {
                cout << ' ';
            } else if(board[i][j] == 1) {
                cout << 'O';
            } else {
                cout << 'X';
            }
            if(j != 2) {
                cout << '|';
            }
        }
        cout << endl;
        if(i != 2) {
            cout << "-+-+-\n";
        }
    }
}

int tileOfNum(int n) {
    if(n == 7) {return 0;}    
    if(n == 8) {return 1;}
    if(n == 9) {return 2;}
    if(n == 4) {return 10;}
    if(n == 5) {return 11;}
    if(n == 6) {return 12;}
    if(n == 1) {return 20;}
    if(n == 2) {return 21;}
    if(n == 3) {return 22;}
    return 0;
}

int checkWinner(int board[3][3]) {
    if(board[0][0] != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
        return board[0][0];
    }
    if(board[1][0] != 0 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
        return board[1][0];
    }
    if(board[2][0] != 0 && board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
        return board[2][0];
    }
    if(board[0][0] != 0 && board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
        return board[0][0];
    }
    if(board[0][1] != 0 && board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
        return board[0][1];
    }
    if(board[0][2] != 0 && board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
        return board[0][2];
    }
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[2][0] != 0 && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return board[2][0];
    }
    return 0;
}

void playerMove() {
    int input, i, j;
    while(true) {
        cin >> input;
        i = tileOfNum(input) / 10;
        j = tileOfNum(input) % 10;
        if(board [i][j] == 0) {
            if(freeCell % 2 == 0) {
                board [i][j] = 2;
            } else {
                board [i][j] = 1;
            }
            freeCell--;
            break;
        }
        draw();
        cout << "The tile is unavalible!\n";
    }
}

int main() {
    int mode, turn;
    while(true) {
        init();

        cout << "Controlls:\nChoose the tile by keyboard's numpad.\n\nWhich player (1 or 2) you want to be? ";
        cin >> mode;

        while(freeCell > 0 && checkWinner() == 0) {
            draw();
            if(mode % 2 == freeCell % 2) {
                playerMove();
            } else {
                //cpuMove(mode);
                playerMove();
            }
        }
        draw();
        if(checkWinner() == 1) {
            cout << "O is the winner!";
        } else if(checkWinner() == 2) {
            cout << "X is the winner!";
        } else {
            cout << "Draw!";
        }
        //usr system ("pause"); for windows os
        pause();
    }
    //return 0;
}