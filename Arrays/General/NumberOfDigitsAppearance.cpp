#include <iostream>
using namespace std;

void countMap(int map[], int num) {
    while(num > 0) {
        map[num%10] += 1;
        num /= 10;
    }
}

int main() {
    int r1 = 1000, r2 = 9999;
    int map[10] = {0};
    for(int i=r1; i<=r2; i++) 
        countMap(map, i);

    for(int i=0; i<10; i++)
        cout << i << " : " << map[i] << endl;
    return 0;
}