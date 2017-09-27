#include <iostream>
using namespace std;

void Twice(int, int&);


int main() {
    int x = 5, y = 8;
    cout << "Calling the function Twice(x,y)" << endl;
    Twice (x,y);
    cout << "The new values of x and y are:" << endl;
    cout << "x is passed by value: " << x << endl;
    cout << "y is passed by reference: " << y << endl;

    return 0;
}

void Twice(int x, int& y) {
    x*=2;
    y*=2;
}