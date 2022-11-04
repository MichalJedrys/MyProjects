#include <iostream>

void reverseArray()
{
    int s;
    std::cout << "Enter size of the array: " << std::endl;
    std::cin >> s;
    int* arr = new int[s];
    int a,b,n;
    std::cout << "Enter numbers in array: " << std::endl;
    for(int k=0;k<s;k++){
        std::cin >> n;
        arr[k]=n;
    }
    for(int i=0;i<s/2;i++){
        a=arr[i];
        b=arr[i];
        arr[i]=arr[s-1-i];
        arr[s-1-i]=b;
    }
    std::cout << std::endl << "Reversed array: " << std::endl;
    for(int j=0;j<s;j++){
        std::cout << arr[j] << " ";
    }  
    std::cout << std::endl;
}