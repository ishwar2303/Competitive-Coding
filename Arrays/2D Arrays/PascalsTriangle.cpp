#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 5;

    int matrix[n][n];

    for(int i=0; i<n; i++) {
        matrix[i][0] = matrix[i][i] = 1;
        
        for(int j=1; j<i; j++)
            matrix[i][j] = matrix[i-1][j] + matrix[i-1][j-1];
        
    }

    for(int i=0; i<n; i++) {
        int spaces = (n/2)-i+1;
        for(int j=0; j<=spaces; j++)
            cout << " ";
        for(int j=0; j<=i; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}