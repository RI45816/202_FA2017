#include <iostream>
using namespace std;

const int NUM_STUDENTS = 25; // maximum number of scores

// Function prototypes - do not change!

int max(int data[], int dataLen);
int min(int data[], int dataLen);
float average(int data[], int dataLen);

int main() {
    int scores[NUM_STUDENTS] = {0};
    int numScores = 0;
    int inputValue;

    /////////////////////////////////////////////////////
    // CODE TO READ SCORES FROM THE KEYBOARD GOES HERE //
    /////////////////////////////////////////////////////

    do {
        cout << "Enter a score (-1 when done): ";
        cin >> inputValue;
        scores[numScores++] = inputValue;
    } while (inputValue != -1 && numScores < NUM_STUDENTS);
    if (inputValue == -1)
        numScores--;

    int maxVal = max(scores, numScores); // compute maximum score

    //////////////////////////////////////////
    // CALLS TO min() AND average() GO HERE //
    //////////////////////////////////////////
    int minVal = min(scores, numScores); // compute maximum score
    float avgVal = average(scores, numScores); // compute maximum score

    cout << "Max score is " << maxVal << endl;
    cout << "Min score is " << minVal << endl;
    cout << "Average is " << avgVal << endl;

    return 0;
}

// max() - computes maximum value in an int array
// Assumes data[] contains at least one element

int max(int data[], int dataLen) {
    int currentMax = data[0];
    for (int i = 1; i < dataLen; i++) {
        if (data[i] > currentMax) {
            currentMax = data[i];
        }
    }
    return currentMax;
}

////////////////////////////////////////////////////
// IMPLEMENTATIONS OF min() AND average() GO HERE //
////////////////////////////////////////////////////

int min(int data[], int dataLen) {
    int currentMin = data[0];
    for (int i = 1; i < dataLen; i++) {
        if (data[i] < currentMin) {
            currentMin = data[i];
        }
    }
    return currentMin;
}

float average(int data[], int dataLen) {
    int currentScore = data[0];
    for (int i = 1; i < dataLen; i++) {
        currentScore += data[i];
    }
    return currentScore / (double) dataLen;
} 