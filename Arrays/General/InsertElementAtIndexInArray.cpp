#include <iostream>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int yIndex = 3;
    int y = 100;
    int i;
    for(i=n-1; i>yIndex; i--) {
        arr[i] = arr[i-1];
    }

    arr[i] = y;

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}