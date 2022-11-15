#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int ind, int sum) {
    
    if(sum == 0) return true;
    
    if(arr[ind] == sum) return true;
    
    if(ind == 0) return false;
    
    bool notTake = isSubsetSum(arr, ind-1, sum);
    bool take = false;
    
    if(arr[ind] <= sum) take = isSubsetSum(arr, ind-1, sum-arr[ind]);
    
    return notTake | take;
    
}

int main()
{
    int arr[] = {3, 7, 4, 2, 8, 9, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 19;
    bool result = isSubsetSum(arr, n-1, sum);
    string status = result ? "Subset with given sum found" : "No subset found for the given sum";
    cout << status << endl;
    return 0;
}
