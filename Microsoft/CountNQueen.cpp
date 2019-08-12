//
//  main.cpp
//  nQueenCount
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// You have an N by N board. Write a function that, given
// N, return the number of possible arrangements of the
// board where N queens can be placed on the board
// without threating each other, i.e. no two queens
// share the same row, column, or diagonal.

#include <iostream>

void clearBoard(char board[][100], int m, int n);
bool canPlace(char board[][100], int N, int r, int c);
bool solveNQueen(char board[][100], int N, int r = 0);
void count(bool flag);

int main(){
    char board[100][100];
    int N; std::cin >> N;
    clearBoard(board, N, N);
    
    solveNQueen(board, N);
    count(true);
}

void clearBoard(char board[][100], int m, int n){
    for (int r = 0; r < m; ++r){
        for (int c = 0; c < n; ++c){
            board[r][c] = 'X';
        }
    }
}

bool canPlace(char board[][100], int N, int r, int c){
    for(int x = 0; x < N; ++x){
        if (board[x][c] == 'Q')
            return false;
    }
    
    int rowDir[] = {-1, -1};
    int colDir[] = {-1, +1};
    for (int dir = 0; dir < 2; ++dir){
        for (int dist = 1; dist < N; ++dist){
            int nextRow = r + dist * rowDir[dir];
            int nextCol = c + dist * colDir[dir];
            if ((nextRow < 0 or nextRow >= N) or (nextCol < 0 or nextCol >= N)){
                break;
            }
            
            if (board[nextRow][nextCol] == 'Q')
                return false;
        }
    }
    return true;
}

bool solveNQueen(char board[][100], int N, int r){
    if (r == N){
        count(false);
        return true;
    }
    
    bool result = false;
    for (int c = 0; c < N; ++c){
        bool check = canPlace(board, N, r, c);
        if (check == true){
            board[r][c] = 'Q';
            result = solveNQueen(board, N, r + 1) || result;
            board[r][c] = 'X';
        }
    }
    return result;
}

void count(bool flag) {
    static int count = 0;
    if (flag)
        std::cout << count << std::endl;
    else
        count++;
}
