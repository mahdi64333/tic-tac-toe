#include <iostream>

using namespace std;

void pause() {
    cout << "\nPress enter...";
    cin.ignore().get();
}

int fact(int n) {
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
                cout << 'X';
            } else {
                cout << 'O';
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
    cout << endl;
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

int getGrade(int board [3][3], int tile, int freeCount, int turn, int cpu) {
    int newBoard [3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            newBoard [i][j] = board [i][j];
        }
    }
    
    newBoard [tileOfNumI(tile)][tileOfNumJ(tile)] = turn;
    freeCount--;
    if(freeCount == 0) {
        return 0;
    }
    if(checkWinner(newBoard) != 0) {
        return fact(freeCount) * cpu * turn;
    }
    int grade = 0;
    for(int testTile = 1; testTile <= 9; testTile++) {
        if (newBoard [tileOfNumI(testTile)][tileOfNumJ(testTile)] == 0) {
            grade += getGrade(newBoard, testTile, freeCount, -turn, cpu);
        }
    }
    return grade;
}

int main() {
    int mode, turn, freeCount, input, board [3][3] , cpu, player;
    while(true) {
        system("clear"); //Use system("cls") for windows os
        freeCount = 9;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }

        cout << "Controlls:\nChoose the tile by keyboard's numpad.\n\nWhich player (1 or 2) you want to be? ";
        cin >> mode;

        if(mode == 1) {
            player = 1;
            cpu = -1;
        } else {
            player = -1;
            cpu = 1;
        }
        

        while(freeCount > 0 && checkWinner(board) == 0) {
            draw(board);
            if(mode % 2 == freeCount % 2) {
                while(true) {
                    cin >> input;
                    if(board [tileOfNumI(input)][tileOfNumJ(input)] == 0) {
                        board [tileOfNumI(input)][tileOfNumJ(input)] = player;
                        freeCount--;
                        break;
                    }
                draw(board);
                cout << "The tile is unavalible!\n";
                }
            } else {
                int chooseTile;
                int grade = -999;
                for(int tile = 1; tile <= 9; tile++) {
                    if(board [tileOfNumI(tile)][tileOfNumJ(tile)] == 0) {
                        int newGrade = getGrade(board, tile, freeCount, cpu, cpu);
                        if(newGrade > grade) {
                            grade = newGrade;
                            chooseTile = tile;
                        }
                    }
                }
                board [tileOfNumI(chooseTile)][tileOfNumJ(chooseTile)] = cpu;
                freeCount--;
            }
        }

        draw(board);
        if(checkWinner(board) == -1) {
            cout << "O is the winner!\n";
        } else if(checkWinner(board) == 1) {
            cout << "X is the winner!\n";
        } else {
            cout << "Draw!\n";
        }
        //usr system ("pause"); for windows os
        pause();
    }
    //return 0;
}