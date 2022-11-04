#pragma once
#include <iostream>

void mergeArrays(int s1, int s2, int* arr1, int* arr2, int* arr)
{
    if (s1 != s2) {
        int n = s1 + s2;
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    else {
        for (int i = 0; i < s2; i++) {
            arr[i] = arr1[i];
        }
        for (int i = s2; i < s1+s2; i++) {
            arr[i] = arr2[i - s2];
        }
    }
}