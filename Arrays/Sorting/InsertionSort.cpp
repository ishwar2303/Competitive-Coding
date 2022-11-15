#include <iostream>
using namespace std;

int main() {

    int arr[] = {7, 3, 4, 1, 6, 5, 2};
    int n = 7;

    // Insertion sort

    // sort first two elements
    int temp;

    if(arr[0] > arr[1]) {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }

    for(int i=1; i<n-1; i++) {
        int x = i;
        
        while(x < n-1) {
            if(arr[x] > arr[x+1]) { // swap required
                temp = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = temp;
                break;
            }
            x++;
        }
        for(int j=i; j>0; j--) {
            if(arr[j] < arr[j-1]) { // swap required in sorted part
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}