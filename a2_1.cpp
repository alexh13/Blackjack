/*
Alex Hughes
1/30/2019

Assignment 2.1
A command line game that plays a simple version of blackjack.
 */


#include <iostream>
#include <string>

using namespace std;

// Gets random number between 1 and 10
int getRandom() {
    int num = 1 + rand() % 10;
    return num;
}


int main() {

    int count, firstCards, currentCards, cardTotal;
    int firstRandom = getRandom(), secondRandom = getRandom(), thirdRandom = getRandom();
    string playAgain, answer;

    // Player score
    cout << "First Cards: " << firstRandom << ", " << secondRandom << endl;
    currentCards = firstRandom + secondRandom;
    cout << "Total: " << currentCards << endl;

    // Ask user for input
    cout << "Do you want another card? (y/n): " << endl;
    cin >> answer;

    // loop for getting another card
    if (answer == "y") {
        cout << "Card: " << thirdRandom << endl;
        cout << "Total: " << currentCards + thirdRandom << endl;
    }



    return 0;
}