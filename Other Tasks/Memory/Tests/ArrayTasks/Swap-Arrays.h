#pragma once
#include <iostream>

void swapArrays(int s1, int s2, int* arr1, int* arr2)
{
    if (s1 != s2) {
        return;
    }
    else {
        std::cout << "BBBBBBBBBBBBBB";
        int temp;
        for (int i = 0; i < s1; i++) {
            temp = arr1[i];
            arr1[i] = arr2[i];
            arr2[i] = temp;
        }
    }
}