#include <iostream>
using namespace std;

int getScore();
void printLetter(int, int, int);

int getScore() {
    int score;
    do {
        cout << "Enter your score (0-100):" << endl;
        cin >> score;
    } while (score > 100 || score < 0);
    return score;
}

void printLetter(int score1, int score2, int score3) {
    cout << "You earned a";
    switch ((score1 + score2 + score3) / 30) {
        case 10:
        case 9:
            cout << "n A";
            break;
        case 8:
            cout << " B";
            break;
        case 7:
            cout << " C";
            break;
        case 6:
            cout << " D";
            break;
        default:
            cout << "n E";
            break;
    }
}

int main() {
    printLetter(getScore(), getScore(), getScore());
    return 0;
}
