#include <iostream>
using namespace std;

int main() {

    int arr[] = {7, 3, 4, 1, 6, 5, 2};
    int n = 7;

    // Bubble Sort
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}