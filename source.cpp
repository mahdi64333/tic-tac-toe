#include <iostream>

using namespace std;

void pause() {
    cout << "\nPress enter...";
    cin.ignore().get();
}

int fi(int n) {
    int f = 1;
    for (n; n > 1; n--) {
        f *= n;
    }
    return f;
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

int tileOfNumI(int n) {
    if(n == 7) {return 0;}    
    if(n == 8) {return 0;}
    if(n == 9) {return 0;}
    if(n == 4) {return 1;}
    if(n == 5) {return 1;}
    if(n == 6) {return 1;}
    if(n == 1) {return 2;}
    if(n == 2) {return 2;}
    if(n == 3) {return 2;}
    return 0;
}

int tileOfNumJ(int n) {
    if(n == 7) {return 0;}    
    if(n == 8) {return 1;}
    if(n == 9) {return 2;}
    if(n == 4) {return 0;}
    if(n == 5) {return 1;}
    if(n == 6) {return 2;}
    if(n == 1) {return 0;}
    if(n == 2) {return 1;}
    if(n == 3) {return 2;}
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

int main() {
    int mode, turn, freeCell, input, board [3][3];
    while(true) {
        system("clear"); //Use system("cls") for windows os
        freeCell = 9;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }

        cout << "Controlls:\nChoose the tile by keyboard's numpad.\n\nWhich player (1 or 2) you want to be? ";
        cin >> mode;

        while(freeCell > 0 && checkWinner(board) == 0) {
            draw(board);
            if(mode % 2 == freeCell % 2) {
                while(true) {
                    cin >> input;
                    if(board [tileOfNumI(input)][tileOfNumJ(input)] == 0) {
                        if(freeCell % 2 == 0) {
                            board [tileOfNumI(input)][tileOfNumJ(input)] = 2;
                        } else {
                            board [tileOfNumI(input)][tileOfNumJ(input)] = 1;
                        }
                        freeCell--;
                        break;
                    }
                }
            } else {
                int chooseTile;
                for(int tile = 1; tile <= 9; tile++) {
                    int grade = 0;
                    if(board [tileOfNumI(tile)][tileOfNumJ(tile)] == 0) {
                        int newGrade = getGrade(tile);
                        if(newGrade > grade) {
                            grade = newGrade;
                            chooseTile = tile;
                        }
                    }
                }
                if(freeCell % 2 == 0) {
                    board [tileOfNumI(input)][tileOfNumJ(input)] = 2;
                } else {
                    board [tileOfNumI(input)][tileOfNumJ(input)] = 1;
                }
            }
        }

        draw(board);
        cout << "The tile is unavalible!\n";
        draw(board);
        if(checkWinner(board) == 1) {
            cout << "O is the winner!\n";
        } else if(checkWinner(board) == 2) {
            cout << "X is the winner!\n";
        } else {
            cout << "Draw!\n";
        }
        //usr system ("pause"); for windows os
        pause();
    }
    //return 0;
}