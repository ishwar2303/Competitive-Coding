#include <iostream>
#include <vector>

using namespace std;

struct CountMap {
    int data;
    int count;
};


void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int sortByCount(CountMap a, CountMap b) {
    if(a.count > b.count)
        return 1;
    else if(a.count == b.count) 
        if(a.data > b.data)
            return 1;
    return 0;
}
vector<CountMap> countOccurrences(int arr[], int n) {
    int searchElement = arr[0];
    int count = 1;

    vector<CountMap> cm;

    for(int i=1; i<n; i++) {
        if(arr[i] == searchElement) {
            count++;
        }
        else {
            // cout << searchElement << " : " << count << endl;
            CountMap map;
            map.data = searchElement;
            map.count = count;

            cm.push_back(map);

            searchElement = arr[i];
            count = 1;
        }
    }
    // cout << searchElement << " : " << count << endl;

    CountMap map;
    map.data = searchElement;
    map.count = count;
    cm.push_back(map);

    // for(int i=0; i<cm.size(); i++) {
    //     cout << cm[i].data << " : " << cm[i].count << endl;
    // }

    return cm;
}

int main() {

    int arr[] = {7, 2, 1, 2, 5, 6, 3, 3, 2, 4, 1, 6, 7, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Array: ";
    printArray(arr, n);

    // Sort Array
    sort(arr, arr+n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    vector<CountMap> cm = countOccurrences(arr, n);

    sort(cm.begin(), cm.end(), sortByCount);

    for(int i=0; i<cm.size(); i++) {
        cout << cm[i].data << " : " << cm[i].count << endl;
    }
    return 0;

}