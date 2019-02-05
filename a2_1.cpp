/*
Alex Hughes
2/3/2019

Assignment 2.1
A command line game that plays a simple version of blackjack.
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

// Gets random number between 1 and 10
int getRandom() {
    int num = 1 + rand() % 10;
    return num;
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int currentCards, cardTotal;
    int firstRandom = getRandom(), secondRandom = getRandom(), loopRandom = getRandom();
    string playAgain, newCard, newGame;

    // Player score
    cout << "First Cards: " << firstRandom << ", " << secondRandom << endl;
    currentCards = firstRandom + secondRandom;
    cout << "Total: " << currentCards << endl;

    // Ask user for input
    cout << "Do you want another card? (y/n): " << endl;
    cin >> newCard;

    // loop for getting another card
    while (newCard == "y" && currentCards < 21) {
        int newNum = getRandom();
        
        cout << "Card: " << newNum << endl;
        cout << "Total: " << currentCards + newNum << endl;
        cout << "Do you want another card? (y/n): " << endl;
        cin >> newCard;
    }

    cardTotal = currentCards + loopRandom;

    // loop for ending game
    while (newCard == "n") {
        if (cardTotal > 21) {
            cout << "Bust!" << endl;
        }
        else if (cardTotal == 21) {
            cout << "Win!" << endl;
        }
        else if (cardTotal < 21) {
            cout << "Thanks for playing" << endl;
        }
        break;
    }

    // new game
    cout << "Would you like to play again? (y/n): " << endl;
    cin >> playAgain;
    if (playAgain == "y") {
         cout << "some text:" << endl;

    }

    return 0; 
}

