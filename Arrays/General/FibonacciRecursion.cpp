#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
// 1 2 3 4 5 6 7 8  9  .....
// 0 1 1 2 3 5 8 13 21 .....
int main() {
    int n = 9;
    cout << fibonacci(n) << endl;
    return 0;
}