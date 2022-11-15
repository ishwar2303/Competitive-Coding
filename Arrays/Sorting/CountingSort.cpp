#include <iostream>
#include <limits.h>
using namespace std;

int maximum(int arr[], int n) {
    int max = INT_MIN;
    
    for(int i=0; i<n; i++)
        if(max < arr[i])
            max = arr[i];
    
    return max;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}


void countingSort(int arr[], int n) {
    
    // find maximum element in array
    int size = maximum(arr, n) + 1;
    
    // create couting array
    int *countingArray = new int[size];
    
    // store zero in counting array
    for(int i=0; i<size; i++)
        countingArray[i] = 0;
        
    // store count of elements in counting array
    for(int i=0; i<n; i++) 
        countingArray[arr[i]] += 1;    
    
    // make counting cumulative
    for(int i=1; i<size; i++) 
        countingArray[i] = countingArray[i] + countingArray[i-1];
        
    int *sortedArray = new int[n];
    for(int i=0; i<n; i++) {
        
        int position = countingArray[arr[i]];
        
        sortedArray[position-1] = arr[i];
        countingArray[arr[i]] -= 1;
    }
    
    printArray(sortedArray, n);
}

int main()
{
    int arr[] = {7, 1, 1, 6, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    countingSort(arr, n);
    
    return 0;
}
