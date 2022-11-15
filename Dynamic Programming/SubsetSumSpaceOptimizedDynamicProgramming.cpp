#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    vector<bool> prev(sum+1), curr(sum+1);

    prev[0] = curr[0] = true;
    for(int i=1; i<=sum; i++)
        prev[i] = arr[0] == i ? true : false;


    for(int i=1; i<n; i++) {
        for(int target=0; target<=sum; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[i] <= target) take = prev[target-arr[i]];
            curr[target] = take | notTake;
        }
        prev = curr;
    }

    return prev[sum];
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
