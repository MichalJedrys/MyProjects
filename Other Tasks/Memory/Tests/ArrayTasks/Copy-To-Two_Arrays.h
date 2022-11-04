#pragma once

void copyToTwoArrays(int s, int* arr, int* arr1, int* arr2)
{
    int s2 = s / 2;
    if (s % 2 == 1) {
        for (int i = 0; i < s2; i++) {
            arr1[i] = 0;
            arr2[i] = 0;
        }
    }
    else {
        
        for (int i = 0; i < s2; i++) {
            arr1[i] = arr[i];
        }
        for (int i = 0; i < s2; i++) {
            arr2[i] = arr[i + s2];
        }
    }
}