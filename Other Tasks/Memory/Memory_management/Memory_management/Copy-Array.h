#pragma once
#include <iostream>

void copyArray()
{
    int s,n,pos=0;
    std::cout << "Enter size of the array: " << std::endl;
    std::cin >> s;
    if (s > 65536) { throw outOfRange(); }
    int* arr = new int[s];
    std::cout << "Enter numbers in array: " << std::endl;
    for(int k=0;k<s;k++){
        std::cin >> n;
        arr[k]=n;
    }
    int* arr_copy = new int[s];
    for(int i=0;i<s;i++){
        
        if (arr[i]>0){
            arr_copy[pos]=arr[i];
            pos++;
        }
    }
    for(int i=0;i<s;i++){
        
        if (arr[i]==0){
            arr_copy[pos]=arr[i];
            pos++;
        }
    }
    for(int i=0;i<s;i++){
        if (arr[i]<0){
            arr_copy[pos]=arr[i];
            pos++;
        }
    }
    delete [] arr;
    std::cout << std::endl << "Copied array: " << std::endl;
    for(int j=0;j<s;j++){
        std::cout << arr_copy[j] << " ";
    } 
    std::cout << std::endl;
}