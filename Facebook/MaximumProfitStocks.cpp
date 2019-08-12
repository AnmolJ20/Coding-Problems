//
//  main.cpp
//  MaximumProfitStocks
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Given a array of numbers representing the stock
// prices of a company in chronological order, write a
// function that calculates the maximum profit you could
// have made from buying and selling that stock once.
// You must buy before you can sell it.

// For e.g., given [9, 11, 8, 5, 7, 10], you should return
// 5, since you could buy the stock at 5 dollars and sell it
// at 10 dollars.

#include <iostream>

int profits(int prices[], int n);

int main() {
    int prices[] = {9, 11, 8, 5, 7, 10};
    std::cout << "Maximum profit: " << profits(prices, 6) << std::endl;
}

// O(n^2)
// int profits(int prices[], int size) {
//     int max = -1;
//     for (int i = 0; i < size-1; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (prices[j] - prices[i] > max)
//                 max = prices[j] - prices[i];
//         }
//     }

//     return max;
// }

// O(n)
int profits(int prices[], int size) {
    int min = prices[0];
    int max = 0;
    
    for (int i = 1; i < size; i++) {
        if (prices[i] - min > max)
            max = prices[i] - min;
        if (prices[i] < min)
            min = prices[i];
    }
    
    return max;
}
