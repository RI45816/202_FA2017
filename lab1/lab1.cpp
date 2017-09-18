#include <iostream> 
using namespace std;

int main() {

    int first, second, third;
    char name[80];
    cout << "Enter your first name:" << endl;
    cin >> name;
    cout << "Enter your first grade:" << endl;
    cin >> first;
    cout << "Enter your second grade:" << endl;
    cin >> second;
    cout << "Enter your third grade:" << endl;
    cin >> third;
    cout << name << " your average is " << (first + second + third) / 3.0 << endl;
    return 0;
}
