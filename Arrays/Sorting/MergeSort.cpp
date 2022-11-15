#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {

    int leftArraySize = mid - left + 1; // calculate size for left array
    int rightArraySize = right - mid; // calculate size for right array

    int *leftArray = new int[leftArraySize]; // create left array
    int *rightArray = new int[rightArraySize]; // create right array


    for(int i=0; i<leftArraySize; i++) // store elements from main array to left array
        leftArray[i] = arr[left + i];
    
    for(int i=0; i<rightArraySize; i++) // store elements from main array to right array
        rightArray[i] = arr[mid + i + 1];

    int mergeArrayIndex = left;
    int leftIndex = 0, rightIndex = 0;

    while(leftIndex < leftArraySize && rightIndex < rightArraySize) {
        if(leftArray[leftIndex] <= rightArray[rightIndex]) 
            arr[mergeArrayIndex++] = leftArray[leftIndex++];
        else arr[mergeArrayIndex++] = rightArray[rightIndex++];
    }

    while(leftIndex < leftArraySize)
        arr[mergeArrayIndex++] = leftArray[leftIndex++];
    
    while(rightIndex < rightArraySize)
        arr[mergeArrayIndex++] = rightArray[rightIndex++];


    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(int arr[], int begin, int end) {
    if(begin >= end)
        return;

    int mid = (begin + end)/2;

    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main() {

    int arr[] = {7, 2, 6, 3, 4, 1, 5};
    int n = 7;

    mergeSort(arr, 0, n-1);

    printArray(arr, n);



    return 0;
}