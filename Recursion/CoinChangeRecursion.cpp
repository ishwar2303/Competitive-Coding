#include <iostream>
#include <vector>
using namespace std;

static int ways;

void numberOfWaysToGiveChange(int coins[], int n, int sum) {

    // possible combination of coins found to give change
    // permutation wise
    // 1 1 3 = 5
    // 1 3 1 = 5 will be consider two different ways 
    if(sum == 0) {
        ways++;
        return;
    }

    // change cannot be given
    if(sum < 0) return;

    for(int i=0; i<n; i++) {
        numberOfWaysToGiveChange(coins, n, sum-coins[i]);
    }
        
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 4;

    numberOfWaysToGiveChange(arr, n, sum);
    cout << "Number of ways to give change for " << sum << " = " << ways << endl;
    return 0;
}