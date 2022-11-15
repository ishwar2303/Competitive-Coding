#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int maximum(int arr[], int n) {
    int max = INT_MIN;

    for(int i=0; i<n; i++) 
        if(max < arr[i])
            max = arr[i];

    return max;
}
void countSort(int arr[], int n, int exp) {

    int countingArray[10] = {0};

    int sortedArray[n];

    for(int i=0; i<10; i++)
        countingArray[i] = 0;

    for(int i=0; i<n; i++) {
        int remainder = (arr[i]/exp)%10;
        countingArray[remainder] += 1;
    }

    for(int i=1; i<10; i++) 
        countingArray[i] = countingArray[i] + countingArray[i-1];
    
    for(int i=n-1; i>=0; i--) {
        int index = (arr[i]/exp)%10;
        int position = countingArray[index];
        countingArray[index] -= 1;
        sortedArray[position-1] = arr[i];
    }
    
    for(int i=0; i<n; i++) 
        arr[i] = sortedArray[i];

}

void radixSort(int arr[], int n) {
    int max = maximum(arr, n);
    for(int exp=1; max/exp>0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr[] = {273, 47, 623, 19, 371, 7821, 8, 673, 355, 29, 192, 41};
    int n = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr, n);

    printArray(arr, n);

    return 0;
}