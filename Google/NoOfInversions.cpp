//
//  main.cpp
//  InversionCount
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// We can determine how "out of order" an array A is by
// counting the number of inversions it has. Two
// elements A[i] and A[j] form an inversion if A[i] > A[j]
// but i < j. That is, a smaller element appears after a
// larger element.

// Given an array, count the number of inversion it has.
// Do this faster than O(N^2) time.

// You may assume each element in the array is distinct.

// For e.g., a sorted list has zero inversion. The
// array [2, 4, 1, 3, 5] has three inversion: (2, 1), (4, 1),
// and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions:
// every distinct pair forms an inversion.

#include <iostream>

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
int mergeSort(int arr[], int array_size);

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    std::cout << "Number of inversions: " << mergeSort(arr, 5) << std::endl;
}

int _mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;
    
    i = left;
    j = mid;
    k = left;
    
    while ((i <= mid - 1) and (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int mergeSort(int arr[], int array_size) {
    int *temp = new int[array_size];
    int ans = _mergeSort(arr, temp, 0, array_size - 1);
    delete[] temp;
    return ans;
}
