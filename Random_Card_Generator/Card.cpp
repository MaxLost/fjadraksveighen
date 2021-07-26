#include <iostream>
#include "Card.h"

Card::Card() {
        type = -1;
        suit = -1;
};

void Card::SetProperties(int t, int s) {
    // Check on wrong values of card properties
    if ((s < 0 || s > 3) || (t < 2 || t > 14)) { 
        std::cout << "Wrong suit or card type" << std::endl;
        exit(EXIT_FAILURE);
    }
    type = t;
    suit = s;
};

void Card::GetProperties(int& t, int& s) {
    t = type;
    s = suit;
}
Card::~Card() {

};