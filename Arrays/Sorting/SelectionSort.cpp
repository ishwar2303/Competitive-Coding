#include <iostream>
using namespace std;

int main() {

    int arr[] = {7, 3, 4, 1, 6, 5, 2};
    int n = 7;

    // Selection Sort
    for(int i=0; i<n; i++) {
        int smallest = INT_MAX;
        int smallest_element_found_at_index = -1;
        for(int j=i; j<n; j++) {
            if(smallest > arr[j]) {
                smallest = arr[j];
                smallest_element_found_at_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = smallest;
        arr[smallest_element_found_at_index] = temp;

    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}