#include <iostream> 
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
    
}

void heapSort(int arr[], int n) {

    for(int i=(n/2)-1; i>=0; i--) { // traverse internal nodes
        heapify(arr, n, i);
    }

    for(int i=n-1; i>0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }

}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main() {

    int arr[] = {7, 3, 4, 1, 6, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}