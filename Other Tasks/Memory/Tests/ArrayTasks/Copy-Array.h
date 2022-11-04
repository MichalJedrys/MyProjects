#pragma once

void copyArray(int s, int* arr, int* arr_copy)
{
    int pos=0;
    for (int i = 0; i < s; i++) {

        if (arr[i] > 0) {
            arr_copy[pos] = arr[i];
            pos++;
        }
    }
    for (int i = 0; i < s; i++) {

        if (arr[i] == 0) {
            arr_copy[pos] = arr[i];
            pos++;
        }
    }
    for (int i = 0; i < s; i++) {
        if (arr[i] < 0) {
            arr_copy[pos] = arr[i];
            pos++;
        }
    }
}