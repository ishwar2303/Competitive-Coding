#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 2, 3, 8, 1, 10, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxProduct;
    int product = 1, j=0;
    for(int i=0; i<k; i++) {
        product *= arr[i];
    }
    maxProduct = product;
    for(int i=k; i<n; i++, j++) {
        product /= arr[j];
        product *= arr[i];
        
        maxProduct = maxProduct < product ? product : maxProduct;
        cout << maxProduct << endl;
    }
    
    return 0;
}