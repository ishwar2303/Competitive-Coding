#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct CountMap {
    int data;
    int count;
};

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<CountMap> maximumCountOfMaximumNumber(int arr[], int n) {
    int count, maximum = INT_MIN, mainCount, mainElement;
    vector<CountMap> cm;
    for(int i=0; i<n; i++) {

        if(maximum != arr[i]) {
            CountMap m;
            m.count = count;
            m.data = maximum;
            cm.push_back(m);
            // cout << maximum << ", " << count << endl;
            count = 1;
            maximum = arr[i];
            if(i == n-1) {
                m.count = count;
                m.data = maximum;
                cm.push_back(m);
            }
        }
        else if(maximum == arr[i]) {
            count++;
        }

        if(count > mainCount) {
            mainCount = count;
            mainElement = arr[i];
        }
    }

    for(CountMap m : cm) {
        cout << "Number: " << m.data << ", Count: " << m.count << endl;
    }
    
    return cm;
}

int main() {

    int arr[] = {7, 4, 5, 1, 2, 1, 5, 7, 8 , 9, 3, 4 , 5, 3, 7 ,1 , 6 , 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);

    printArray(arr, n);

    vector<CountMap> cm = maximumCountOfMaximumNumber(arr, n);

    

    return 0;
}