#include <iostream>
using namespace std;

int main() {
    int arr[] = {7, 3, 4, 1, 6, 5, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maximumSum = INT_MIN;

    // for(int i=0; i<=n-k; i++) {
    //     int sum = 0;
    //     for(int j=0; j<k; j++) {
    //         sum += arr[i+j];
    //     }

    //     maximumSum = max(sum, maximumSum);

    // }

    int sum = 0;
    for(int i=0; i<k; i++) {
        sum += arr[i];
    }

    maximumSum = sum;

    for(int i=1, j=0; i<=n-k; i++, j++) {
        sum = sum + arr[i] - arr[j];

        maximumSum = max(sum, maximumSum);
    }

    cout << maximumSum << endl;

    return 0;
}