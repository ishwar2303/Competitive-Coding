#include <iostream>
#include <vector>
using namespace std;

vector<int> findTriplet(int arr[], int n)
{
    sort(arr, arr+n);
    vector<int> result;
    
    for(int i=0; i<n; i++) {
        int l = 0;
        int r = n-1;
        while(l<r) {
            if(arr[l] + arr[r] == arr[i]) {    
                result.push_back(arr[l]);
                result.push_back(arr[r]);
                result.push_back(arr[i]);
                return result;
            }
            else if(arr[l] + arr[r] < arr[i]) {
                l++;
            }
            else r--;
        }
    }
    
    return result;
    
}

int main() {
    int arr[] = {3, 6, 7, 8, 3, 4, 5, 1, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v = findTriplet(arr, n);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}