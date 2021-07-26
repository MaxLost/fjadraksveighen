#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include "RandomCardGenerator.h"
#include "Card.h"

std::random_device rd;
std::mt19937 rng(rd() + time(nullptr));

RandomCardGenerator::RandomCardGenerator() {};

void RandomCardGenerator::InitPropertiesSets(std::vector <int>& type, std::vector <std::string>& suits) {
    int n = type.size();
    // Values in array: 2-10 — numbers; 11 — Jack; 12 — Queen; 13 — King; 14 — Ace
    for (int i = 0; i < n; i++) // Initializing types of cards;
        type[i] = i + 2;

    suits[0] = "Spades"; // Initializing suits of cards. Refactor when custom suits will be added
    suits[1] = "Clubs";
    suits[2] = "Hearts";
    suits[3] = "Diamonds";
};

void RandomCardGenerator::ShowCard(Card& current_card, std::vector <std::string>& suits) {
    int card_type, card_suit;
    current_card.Card::GetProperties(card_type, card_suit); // Getting properties of current card

    if (card_type == -1 || card_suit == -1) { // Checking correct initialization of current card
        std::cout << "Card initialization error" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << suits[card_suit] << ' ';

    if (card_type <= 10) {  // Checking only upper border because "Card" object can't contain wrong values
        std::cout << card_type << std::endl;
    }
    else {
        switch (card_type) {
        case 11:
            std::cout << "Jack" << std::endl;
            break;
        case 12:
            std::cout << "Queen" << std::endl;
            break;
        case 13:
            std::cout << "King" << std::endl;
            break;
        case 14:
            std::cout << "Ace" << std::endl;
            break;
        default:
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
    };
}

void RandomCardGenerator::GenerateRandomCard() {
    std::vector <std::string> suits(4);
    std::vector <int> type(13);

    RandomCardGenerator::InitPropertiesSets(type, suits);

    std::uniform_int_distribution<int> n(1, 10000);
    int x = n(rng) + 20;

    Card* current_card = new Card;
    (*current_card).Card::SetProperties(type[x % 13], x % 4);

    RandomCardGenerator::ShowCard(*current_card, suits);
    delete current_card;
};

RandomCardGenerator::~RandomCardGenerator() {};