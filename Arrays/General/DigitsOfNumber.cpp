#include <iostream>
using namespace std;

int main() {
    int num = 683709;
    while(num > 0) {
        int remainder = num%10;
        num /= 10;
        cout << remainder << " ";
    }
    return 0;
}