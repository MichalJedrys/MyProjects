#pragma once

void reversedArray(int s, int* arr)
{
    int a, b;
    for (int i = 0; i < s / 2; i++) {
        a = arr[i];
        b = arr[i];
        arr[i] = arr[s - 1 - i];
        arr[s - 1 - i] = b;
    }
}