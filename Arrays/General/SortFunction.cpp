#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {7, 4, 5, 1, 2, 1, 5, 7, 8 , 9, 3, 4 , 5, 3, 7 ,1 , 6 , 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);

    printArray(arr, n);
    return 0;
}