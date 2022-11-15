#include <iostream>
#include <sstream>
using namespace std;

int main() {

    // string str = "1004";
    int n = 1004;
    stringstream stream;
    stream << n;
    string str;
    stream >> str;
    cout << str << endl;
    replace(str.begin(), str.end(), '0', '5');

    cout << str << endl;
    stream.clear();
    stream << str;

    int x;
    stream >> x;
    cout << "x: " << x << endl;

    return 0;
}