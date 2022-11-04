#include <iostream>

void mergeArray()
{
    int s,n;
    std::cout << "Enter size of the target array: " << std::endl;
    std::cin >> s;
    if (s % 2 == 1) { throw notEvenNumber(); }
    int s2=s/2;
    int* arr = new int[2];
    int* arr_one = new int[s2];
    int* arr_two = new int[s2];
    std::cout << "Enter numbers in first subarray: " << std::endl;
    for(int k=0;k<s2;k++){
        std::cin >> n;
        arr_one[k]=n;
    }
    std::cout << "Enter numbers in second subarray: " << std::endl;
    for(int k=0;k<s2;k++){
        std::cin >> n;
        arr_two[k]=n;
    }
    for(int i=0;i<s2;i++){
        arr[i]=arr_one[i];
    }
    for(int i=s2;i<s;i++){
        arr[i]=arr_two[i-s2];
    }    
    delete[] arr_one;
    delete[] arr_two;
    std::cout << std::endl << "Copied array: " << std::endl;
    for(int j=0;j<s;j++){
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
}