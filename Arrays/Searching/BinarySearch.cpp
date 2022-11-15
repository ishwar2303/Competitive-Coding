#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int start = 0;
    int end = n-1;

    while(start <= end) {
        int mid = (start+end)/2;

        if(arr[mid] == x) return mid;

        if(arr[mid] > x) end = mid-1;
        else start = mid+1;

    }

    return -1;
}

int main() {
    int arr[] = {3, 6, 7, 9, 10, 24, 67, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 67;

    int index = binarySearch(arr, n, x);

    if(index != -1)
        cout << "Element found at " << index << endl;
    else cout << "Element not found" << endl;

    return 0;
}