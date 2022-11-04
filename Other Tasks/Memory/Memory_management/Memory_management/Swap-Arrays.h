#include <iostream>

void swapArray()
{
    int s,n,pos=0;
    std::cout << "Enter size of the arrays: " << std::endl;
    std::cin >> s;
    int* arr_one = new int[s];
    int* arr_two = new int[s];
    std::cout << "Enter numbers in first array: " << std::endl;
    for(int k=0;k<s;k++){
        std::cin >> n;
        arr_one[k]=n;
    }
    std::cout << "Enter numbers in second array: " << std::endl;
    for(int k=0;k<s;k++){
        std::cin >> n;
        arr_two[k]=n;
    }
    int temp;
    for(int i=0;i<s;i++){
        temp=arr_one[i];
        arr_one[i]=arr_two[i];
        arr_two[i]=temp;
    }
    std::cout << "Swapped arrays: ";
    std::cout << std::endl << "First array: " << std::endl;
    for(int j=0;j<s;j++){
        std::cout << arr_one[j] << " ";
    }  
    std::cout << std::endl << "Second array: " << std::endl;
    for(int j=0;j<s;j++){
        std::cout << arr_two[j] << " ";
    } 
    std::cout << std::endl;
}