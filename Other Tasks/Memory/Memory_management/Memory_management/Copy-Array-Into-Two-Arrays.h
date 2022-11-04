#include <iostream>

void copyArrayIntoTwo()
{
    int s,n;
    std::cout << "Enter size of the array: " << std::endl;
    std::cin >> s;
    if (s % 2 == 1) { throw notEvenNumber(); }
    int s2=s/2;
    int* arr = new int[s];
    int* arr_one = new int[s2];
    int* arr_two = new int[s2];
    std::cout << "Enter numbers in array: " << std::endl;
    for(int k=0;k<s;k++){
        std::cin >> n;
        arr[k]=n;
    }
    int pos1=0,pos2=0;
    for(int i=0;i<s;i++){
        if (i<s2){
            arr_one[i]=arr[i];
        }
        else{
            arr_two[i-s2]=arr[i];
        }
    }
    delete[] arr;
    std::cout << std::endl << "First array: " << std::endl;
    for(int j=0;j<s2;j++){
        std::cout << arr_one[j] << " ";
    }
    std::cout << std::endl << "Second array: " << std::endl;
    for(int j=0;j<s2;j++){
        std::cout << arr_two[j] << " ";
    }  
    std::cout << std::endl;
}