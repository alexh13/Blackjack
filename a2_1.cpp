/*
    Alex Hughes
    2/3/2019
    Assignment 2.1

    This program simulates a simple game of blackjack. The program begins by
    outputting two numbers between 1-10 that represent card numbers and labeled
    with "Card:". The numbers are added together and printed with the label "Total"
    to represent the total of the hand. The user is given the choice of drawing
    another card (user enters 'y'), or ending their turn (user enters 'n'). The
    user may enter their response in lowercase or uppercase. Drawing another card
    will result in another randomly generated number between 1-10 that is added
    to the existing total. If the total of the hand equals or exceeds 21, the program
    will end the turn, outputting "Congratulations!" if the hand equals 21, other-
    wise outputting "BUST".  When the turn is over, the user is asked if they want
    to play again. Once the user has entered 'n' to quit, the program ends without
    further output.
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


    // declared ints & strings
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

/* Output:
First Cards: 6, 8
Total: 14
Do you want another card? (y/n):
y
Card: 2
Total: 16
Do you want another card? (y/n):
y
Card: 10
Total: 26
Bust!
Would you like to play again? (y/n):
n
Thanks for playing!
 */
