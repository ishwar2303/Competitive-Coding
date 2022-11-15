#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = start; // consider first element as pivot
    
    int p = start + 1; // left pointer
    int q = end; // right pointer
    
    // 7, 3, 6, 1, 4, 5, 2
    while(true) {
        // p passed q
        if(p > q) {
            swap(&arr[q], &arr[pivot]);
            pivot = q;
            break;
        }
        
        // p has not passed q
        if(arr[p] > arr[pivot] && arr[q] < arr[pivot]) { 
            swap(&arr[p], &arr[q]);
        }
        
        if(arr[p] < arr[pivot])
            p++;
            
        if(arr[q] > arr[pivot])
            q--;
    }
    
    return pivot;
    
}

void quickSort(int arr[], int start, int end) {
    
    if(start < end) {
        
        int pivot = partition(arr, start, end); // set pivot to correct position
        
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {7, 3, 6, 1, 4, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);
    
    printArray(arr, n);
    

    return 0;
}
