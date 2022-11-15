#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int x) {
    if(start > end) return -1;

    int mid = (start+end)/2;

    if(arr[mid] == x) return mid;

    if(arr[mid] > x) return binarySearch(arr, start, mid-1, x);
    else return binarySearch(arr, mid+1, end, x);
}

int main() {
    int arr[] = {3, 6, 7, 9, 10, 24, 67, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 67;

    int index = binarySearch(arr, 0, n-1, x);

    if(index != -1)
        cout << "Element found at " << index << endl;
    else cout << "Element not found" << endl;

    return 0;
}