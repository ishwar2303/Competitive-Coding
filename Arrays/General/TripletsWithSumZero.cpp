#include <iostream>
#include <unordered_set>

using namespace std;
// Time Complexity O(n^3)
// void triplets(int arr[], int n) {
//     for(int i=0; i<n-2; i++) { // picks first element
//         for(int j=i+1; j<n-1; j++) { // picks second element 
//             for(int k=j+1; k<n; k++) { // picks third element
//                 int sum = arr[i] + arr[j] + arr[k];

//                 if(sum == 0) {
//                     cout << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
//                 }
//             }
//         }
//     }
// }

// Time Complexity O(n^2)
// third number should be negative of (first + second) elements
void triplets(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        unordered_set<int> set;
        for(int j=i+1; j<n; j++) {
            int requiredNumber = -(arr[i] + arr[j]);
            if(set.find(requiredNumber) != set.end()) {
                cout << arr[i] << ", " << arr[j] << ", " << requiredNumber << endl;
            }
            else set.insert(arr[j]);
        }
    }
}

int main() {
    int arr[] = {1, 2, -1, 2, 3, -1, 3, -3, 0, 4, -4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);


    triplets(arr, n);

    return 0;
}