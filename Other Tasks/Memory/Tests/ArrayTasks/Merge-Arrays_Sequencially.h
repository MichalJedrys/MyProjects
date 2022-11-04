#pragma once

void copy_high(int* arr_t, int* arr_s1, int* arr_s2, int s, int& pos) {
    int s2 = s / 2;
    for (int i = 0; i < s2; i++) {
        if (arr_s1[i] > 0) {
            arr_t[pos] = arr_s1[i];
            pos++;
        }
    }
    for (int i = 0; i < s2; i++) {
        if (arr_s2[i] > 0) {
            arr_t[pos] = arr_s2[i];
            pos++;
        }
    }
}

void copy_eq(int* arr_t, int* arr_s1, int* arr_s2, int s, int& pos) {
    int s2 = s / 2;
    for (int i = 0; i < s2; i++) {
        if (arr_s1[i] == 0) {
            arr_t[pos] = arr_s1[i];
            pos++;
        }
    }
    for (int i = 0; i < s2; i++) {
        if (arr_s2[i] == 0) {
            arr_t[pos] = arr_s2[i];
            pos++;
        }
    }
}

void copy_low(int* arr_t, int* arr_s1, int* arr_s2, int s, int& pos) {
    int s2 = s / 2;
    for (int i = 0; i < s2; i++) {
        if (arr_s1[i] < 0) {
            arr_t[pos] = arr_s1[i];
            pos++;
        }
    }
    for (int i = 0; i < s2; i++) {
        if (arr_s2[i] < 0) {
            arr_t[pos] = arr_s2[i];
            pos++;
        }
    }
}

void mergeArraysSequencially(int s1, int s2, int* arr1, int* arr2, int* arr)
{
        int pos = 0;
        int s = s1 + s2;
        if (s1 != s2) {
            int n = s1 + s2;
            for (int i = 0; i < n; i++) {
                arr[i] = 0;
            }
        }
        else {
            copy_high(arr, arr1, arr2, s, pos);
            copy_eq(arr, arr1, arr2, s, pos);
            copy_low(arr, arr1, arr2, s, pos);
        }
}