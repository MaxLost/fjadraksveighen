#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <vector>
#include <string>
#define _UNICODE
#define UNICODE

std::random_device rd;
std::mt19937 rng(rd()+time(nullptr));

class Card {
    private:
    int type;
    int suit;

    public:

    void SetProperties(int t, int s){
        if ((s < 0 || s > 3) || (t < 2 || t > 14)) { // Check on wrong values of card properties
            std::wcout << "Wrong suit or card type" << std::endl;
            exit(EXIT_FAILURE);
        }
        type = t;
        suit = s;
    };

    void GetProperties(int &t, int &s){
        t = type;
        s = suit;
    }
};

class RandomCardGenerator {
private :
    static void InitPropertiesSets(std::vector <int> &type, std::vector <std::string> &suits) {
        int n = type.size(); // "type" array size
        // Values in array: 2-10 — numbers; 11 — Jack; 12 — Queen; 13 — King; 14 — Ace
        for (int i = 0; i < n; i++) // Initializing types of cards;
            type[i] = i + 2;
        
        suits[0] = "Spades"; // Initializing suits of cards. Refactor when custom suits will be added
        suits[1] = "Clubs";
        suits[2] = "Hearts";
        suits[3] = "Diamonds";
    }
    
    static void ShowCard(Card & current_card, std::vector <std::string> &suits) {
        int card_type, card_suit;
        current_card.GetProperties(card_type, card_suit); // Getting properties of current card
        
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
            };
        }
    }

public:
    static void GenerateRandomCard() {
        std::vector <std::string> suits(4);
        std::vector <int> type(13); 
        
        InitPropertiesSets(type, suits);

        std::uniform_int_distribution<int> n(1, 10000);
        int x = n(rng) + 20;

        int a = x % 4;
        int b = type[x % 13];
        Card* current_card = new Card;
        (*current_card).SetProperties(b, a);

        ShowCard(*current_card, suits);
    }
};

int main(){
    using namespace std;
    int n;
    cout << "Enter amount of cards you would to generate: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        RandomCardGenerator::GenerateRandomCard();
    }
    system("pause");
    return 0;
}