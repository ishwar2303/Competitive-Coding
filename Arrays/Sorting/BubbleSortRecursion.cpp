#include <iostream>
using namespace std;

void BubbleSort(int arr[], int i, int n) {
    if(i == 0 && n == 0)
        return;
    
    if(i == n) {
        BubbleSort(arr, 0, n-1);
    }
    else if(arr[i] > arr[i+1]) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        BubbleSort(arr, i+1, n);
    }
    else BubbleSort(arr, i+1, n);
    
    
}

void PrintArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {3, 7, 2, 5, 1, 6, 4};
    int n = 7;
    
    BubbleSort(arr, 0, n-1);
    
    PrintArray(arr, n);

    return 0;
}
