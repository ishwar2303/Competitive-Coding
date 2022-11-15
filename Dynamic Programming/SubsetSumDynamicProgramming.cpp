#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n][sum+1];

    for(int i=0; i<=sum; i++)
        dp[0][i] = arr[0] == i ? true : false;

    for(int i=0; i<n; i++)
        dp[i][0] = true;

    for(int i=1; i<n; i++)
        for(int target=1; target<=sum; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target) take = dp[i-1][target-arr[i]];
            dp[i][target] = take | notTake;
        }

    return dp[n-1][sum];
}

int main()
{
    int arr[] = {3, 7, 4, 2, 8, 9, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 19;
    bool result = isSubsetSum(arr, n, sum);
    string status = result ? "Subset with given sum found" : "No subset found for the given sum";
    cout << status << endl;
    return 0;
}
