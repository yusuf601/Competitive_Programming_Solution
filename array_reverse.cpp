#include <iostream>

//sumber soal :  https://www.hackerrank.com/challenges/arrays-introduction/problem?isFullScreen=true

void InputAngka(int value[], int &n){
    for(int i = 0; i <= n - 1; i++ ){
        std::cout << "Masukkan angka: ";
        std::cin >> value[i];

    }
}


void PrintReverse(int value[],int &n){
    // std::cout << "reverse "<< " ";
    for(int i = n - 1; i >= 0 ; i--){
        std::cout << value[i] << " ";
    }
}
int main(){
    int n;
    std::cout << "Input the size of array: ";
    std::cin >> n;
    
    int value[n];
    InputAngka(value,n);
    PrintReverse(value,n);
    // for(int i = 0; i <= n - 1; i++ ){
    //     std::cout << "Masukkan angka: ";
    //     std::cin >> value[i];

    // }
    // for(int i = 0; i <= n - 1; i++){
    //     std::cout << value[i] << " ";
    // }

    std::cin.get();
    return 0;
}