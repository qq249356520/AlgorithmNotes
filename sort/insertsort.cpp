#include<iostream>

using namespace std;

int main(){
    int arr[5] = {5, 2, 7, 1, 2};

    for(int i = 1; i < 5; i++){
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            swap(arr[j], arr[j - 1]);
    }

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
}
