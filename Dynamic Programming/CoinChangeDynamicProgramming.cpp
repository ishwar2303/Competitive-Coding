#include <iostream>
#include <vector>
using namespace std;

int numberOfWaysToGiveChange(int coins[], int n, int sum) {

        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        
        for(int i=0; i<n; i++) {
            for(int change=coins[i]; change<=sum; change++) {
                dp[change] += dp[change-coins[i]];
            }
        }
        
        return dp[sum];
        
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 4;

    int ways = numberOfWaysToGiveChange(arr, n, sum);
    cout << "Number of ways to give change for " << sum << " = " << ways << endl;
    return 0;
}