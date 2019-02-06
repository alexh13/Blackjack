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


    // declared ints
    int currentCards, firstRandom = getRandom(), secondRandom = getRandom();
    string playAgain, newCard, newGame;


    // Player initial score
    cout << "First Cards: " << firstRandom << ", " << secondRandom << endl;
    currentCards = firstRandom + secondRandom;
    cout << "Total: " << currentCards << endl;


    // Ask user for a new card
    cout << "Do you want another card? (y/n): " << endl;
    cin >> newCard;


    // loop for getting another card
    while (newCard == "y" && currentCards < 21) {
        int newNum = getRandom();
        cout << "Card: " << newNum << endl;
        cout << "Total: " << currentCards + newNum << endl;
        currentCards = currentCards + newNum; // update currentCards int with new total
        if (currentCards > 21) {
            cout << "Bust!" << endl;
            break;
        }
        else if (currentCards == 21) {
            cout << "Win!" << endl;
            break;
        }
        cout << "Do you want another card? (y/n): " << endl;
        cin >> newCard;
    }


    // new game option
    cout << "Would you like to play again? (y/n): " << endl;
    cin >> playAgain;
    if (playAgain == "y") {
         return main();
    }
    else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}

