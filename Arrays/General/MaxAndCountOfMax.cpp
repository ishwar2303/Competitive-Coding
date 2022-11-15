#include <iostream>
using namespace std;

struct Maximum {
    int max;
    int count;
};

Maximum countOfMaximum(int arr[], int n) {
    int max = INT_MIN;
    int count = 0;
    for(int i=0; i<n; i++) {
        if(max < arr[i]) {
            max = arr[i];
            count = 1;
        }
        else if(max == arr[i])
            count++;
    }

    Maximum maximum;
    maximum.max = max;
    maximum.count = count;

    return maximum;
}

int main() {

    int arr[] = {7, 2, 1, 2, 3, 6, 7, 8, 6, 5, 4, 3, 2, 6, 4, 6, 4, 4, 1, 2, 4, 6, 5, 7, 8, 8, 5, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    Maximum maximum = countOfMaximum(arr, n);

    cout << maximum.max << " : " << maximum.count << endl;

    return 0;
}