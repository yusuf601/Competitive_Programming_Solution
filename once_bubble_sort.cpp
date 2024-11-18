#include <iostream>
#include <vector>

//sumber: https://www.codewars.com/kata/56b97b776ffcea598a0006f2/train/cpp

// void OnceBubble(std::vector<int>& value){ ///full bubble sort
//     // bool swapped;
//     for(int i = 0; i <= value.size() - 1; i++){
//         for(int j = i + 1; j <= value.size() - i - 1;j++){
//           if(value[i] > value[i + 1]){
//             int temp = value[i];
//             value[i] = value[i + 1];
//             value[i + 1] = temp;

//         }
//         }
//     }

// }
// THIS SOLUTION CHANGE THE VARIABEL 
void OnceBubble(std::vector<int>& value){
    for(int i = 0; i <= value.size() - 1; i++){
        for(int j = 1; j <= value.size() - i - 1;j++){
          if(value[i] > value[j]){
            int temp = value[j];
            value[i] = value[j];
            value[j] = temp;

        }
        // if(i <= value.size() - 1 & j <= value.size() - i - 1){
        //     break;
        }
        if(i <= value.size() - 1){
            break;        
        }
    }

}


void PrintData(std::vector<int>& value){
    for(int i = 0; i <= value.size() - 1; i++){
        std::cout << value[i] << " ";
    }
}

int main(){
    int n,val;
    std::vector<int> value;
    std::cout << "Masukkan panjang data: ";
    std::cin >> n;
    for(int i = 0;i <= n - 1; i++){
        std::cout << "Masukkan data ke " << i + 1 << ":";
        std::cin >> val;
        value.push_back(val);
    }
    OnceBubble(value);
    PrintData(value);
    

    std::cin.get();
    return 0;
}