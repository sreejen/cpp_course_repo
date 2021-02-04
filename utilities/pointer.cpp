#include <iostream>

using namespace std;

void squared_array(int arr[]) {
    int* pointer = arr;
    for(int i =0;i<6;i++){
        *(pointer) = (*pointer) * (*pointer);
        cout<< *(pointer)<<endl;
        pointer++;
    }
}


int main() {
    
    int arr[] = {4,8,15,16,23,42};
    squared_array(arr);

    return 0;
}