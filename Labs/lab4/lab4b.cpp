#include <iostream>
using namespace std;

void GetName(string*, string*);

int main() {
    string first,  last, *ptrFirst = &first, *ptrLast = &last;
    GetName(ptrFirst, ptrLast);
    cout << "Your name is: " << first << " " << last << endl;
    return 0;
}

void GetName(string * x, string * y) {
    cout << "What is your first name?" << endl;
    cin >> *x;
    cout << "What is your last name?" << endl;
    cin >> *y;
    return;
}