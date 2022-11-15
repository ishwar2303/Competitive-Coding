#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct CountMap {
    int data;
    int count;
};

vector<CountMap> countOccurrences(int arr[], int n) {

    sort(arr, arr+n);
    int searchElement = arr[0];
    int count = 1;

    vector<CountMap> cm;

    for(int i=1; i<n; i++) {
        if(arr[i] == searchElement) {
            count++;
        }
        else {
            CountMap map;
            map.data = searchElement;
            map.count = count;

            cm.push_back(map);

            searchElement = arr[i];
            count = 1;
        }
    }
    CountMap map;
    map.data = searchElement;
    map.count = count;
    cm.push_back(map);

    return cm;
}

int sortByCount(CountMap a, CountMap b) {
    if(a.count > b.count)
        return 1;
    else if(a.count == b.count) 
        if(a.data > b.data)
            return 1;
    return 0;
}

int main() {

    int m, n;
    cin >> m >> n;

    int average, count, price, menu;
    count = 0;
    average = price = INT_MIN;

    for(int i=0; i<m; i++) {
        int *arr = new int[n];
        double sum = 0;
        for(int j=0; j<n; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        double tempAverage = sum/(float)n;

        vector<CountMap> cm = countOccurrences(arr, n);
        sort(cm.begin(), cm.end(), sortByCount);

        int tempCount = cm[0].count;
        int tempPrice = cm[0].data;


        if(count < tempCount) {
            count = tempCount;
            price = tempPrice;
            average = tempAverage;
            menu = i+1;
        }
        else if(count == tempCount) {
            if(price < tempPrice) {
                price = tempPrice;
                average = tempAverage;
                menu = i+1;
            }
            else if(price == tempPrice) {
                if(average < tempAverage) {
                    average = tempAverage;
                    menu = i+1;
                }
            }
        }

        // cout << tempCount << " " << tempPrice << " " << average << endl;
        delete[] arr;
    }

    cout << menu;

    return 0;
}
// 3 15
// 7 3 6 8 9 1 2 2 2 5 6 7 8 1 5
// 7 7 7 8 8 9 9 0 1 1 2 0 4 0 2
// 8 0 9 1 1 2 3 3 3 4 4 7 8 3 4