//
//  main.cpp
//  SodukoSolver
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. The objective is to
// fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) must contain all
// of the digits from 1 to 9.

// Implement an efficient sudoku solver.

#include <iostream>
#include <cmath>

void inMat(int matrix[][9], int r, int c);
void outMat(int matrix[][9], int r, int c);
bool canPlace(int board[][9], const int& n, const int& r, const int& c, const int& number);
bool sodukoSolver(int board[][9], const int& n, const int& r, const int& c);

int main() {
    int board[9][9];
    inMat(board, 9, 9);
    if (sodukoSolver(board, 9, 0, 0))
        outMat(board, 9, 9);
    else
        std::cout << "I can't solve this Soduko!! So do you.";
}

void inMat(int matrix[][9], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void outMat(int matrix[][9], int r, int c) {
    std::cout << std::endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << matrix[i][j] << " ";
        }
        
        std::cout << "\n";
    }
}

bool canPlace(int board[][9], const int& n, const int& r, const int& c, const int& number) {
    for (int x = 0; x < n; ++x){
        if (board[r][x] == number or board[x][c] == number){
            return false;
        }
    }
    
    int rootN = sqrt(n);
    int subBoxStartRow = r - (r % rootN);
    int subBoxStartCol = c - (c % rootN);
    for (int i = subBoxStartRow; i < subBoxStartRow + rootN; i++) {
        for (int c = subBoxStartCol; c < subBoxStartCol + rootN; c++) {
            if (board[i][c] == number) {
                return false;
            }
        }
    }
    
    return true;
}

bool sodukoSolver(int board[][9], const int& n, const int& r, const int& c) {
    if (r == n)
        return true;
    else if (c == n)
        return sodukoSolver(board, n, r+1, 0);
    
    if (board[r][c] != 0)
        return sodukoSolver(board, n, r, c+1);
    
    for (int num = 1; num <= n; num++) {
        if (canPlace(board, n, r, c, num)) {
            board[r][c] = num;
            if (sodukoSolver(board, n, r, c+1))
                return true;
            else
                board[r][c] = 0;
        }
    }
    
    return false;
}