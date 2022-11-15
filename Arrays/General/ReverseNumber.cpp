#include <iostream>
#include <math.h>
using namespace std;

int countNumberOfDigits(int num) {
    int count = 0;
    while(num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int num = 683709;
    
    int digits = countNumberOfDigits(num);
    int x = pow(10, digits-1);
    int reversedNumber = 0;
    while(num > 0) {
        int remainder = num%10;
        num /= 10;

        reversedNumber += remainder*x;

        x /= 10;
    }

    cout << "Reversed Number: " << reversedNumber << endl;

    return 0;
}