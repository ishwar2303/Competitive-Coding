#include <iostream>
using namespace std;

int main() {
    int num = 683709;
    int count = 0;

    while(num > 0) {
        num /= 10;
        count++;
    }

    cout << "Number of Digits: " << count;
    return 0;
}