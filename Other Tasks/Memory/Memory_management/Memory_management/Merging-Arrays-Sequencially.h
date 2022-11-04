#include <iostream>

void copy_high(int *arr_t,int *arr_s1,int *arr_s2, int s, int &pos){
    int s2=s/2;
    for(int i=0;i<s2;i++){
        if (arr_s1[i]>0){
            arr_t[pos]=arr_s1[i];
            pos++;
        }
    }
    for(int i=0;i<s2;i++){
        if (arr_s2[i]>0){
            arr_t[pos]=arr_s2[i];
            pos++;
        }
    }
}

void copy_eq(int *arr_t,int *arr_s1,int *arr_s2, int s, int &pos){
    int s2=s/2;
    for(int i=0;i<s2;i++){
        if (arr_s1[i]==0){
            arr_t[pos]=arr_s1[i];
            pos++;
        }
    }
    for(int i=0;i<s2;i++){
        if (arr_s2[i]==0){
            arr_t[pos]=arr_s2[i];
            pos++;
        }
    }
}

void copy_low(int *arr_t,int *arr_s1,int *arr_s2, int s, int &pos){
    int s2=s/2;
    for(int i=0;i<s2;i++){
        if (arr_s1[i]<0){
            arr_t[pos]=arr_s1[i];
            pos++;
        }
    }
    for(int i=0;i<s2;i++){
        if (arr_s2[i]<0){
            arr_t[pos]=arr_s2[i];
            pos++;
        }
    }
}

void meargeArraySeq()
{
    int s,n,pos=0;
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
    
    copy_high(arr,arr_one,arr_two,s,pos);
    copy_eq(arr,arr_one,arr_two,s,pos);    
    copy_low(arr,arr_one,arr_two,s,pos);
    
    delete[] arr_one;
    delete[] arr_two;

    std::cout << std::endl << "Copied array: " << std::endl;
    for(int j=0;j<s;j++){
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
}