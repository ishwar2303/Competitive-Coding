#include <iostream>
using namespace std;

int fibonacci(int n) {
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;

    for(int i=3; i<=n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];

}
// 1 2 3 4 5 6 7 8  9  .....
// 0 1 1 2 3 5 8 13 21 .....
int main() {
    int n = 5;
    cout << fibonacci(n) << endl;
    return 0;
}