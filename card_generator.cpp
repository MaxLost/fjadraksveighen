#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include <random>
#define _UNICODE
#define UNICODE

std::random_device rd;
std::mt19937 rng(rd()+time(nullptr));

class Card {
    private:
    int type;
    wchar_t suit;

    public:

    void init(int t, wchar_t s){
        if ((s != L'S') && (s != L'C') && (s != L'H') && (s != L'D')){
            std::wcout << "Wrong suit" << std::endl;
            exit(EXIT_FAILURE);
        }
        type = t;
        suit = s;
    };

    void get(int &t, wchar_t &s){
        t = type;
        s = suit;
    }
};

void random_card(){
    wchar_t suits[4]; suits[0] = 'S'; suits[1] = 'C'; suits[2] = 'H'; suits[3] = 'D';
    // suits = ['\u2661', '\u2662', '\u2664', '\u2667']
    // int type [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14];   
    
    int type[13]; // 2-10 — numbers; 11 — Jack; 12 — Queen; 13 — King; 14 — Ace
    type[0] = 2; type[1] = 3; type[2] = 4; type[3] = 5; type[4] = 6; type[5] = 7; type[6] = 8; type[7] = 9; type[8] = 10;
    type[9] = 11; type[10] = 12; type[11] = 13; type[12] = 14;

    std::uniform_int_distribution<int> n(1, 10000);
    int x = n(rng) + 20;
    // std::wcout << x << std::endl;
    
    wchar_t *a = &suits[x % 4];
    int *b = &type[x % 13];
    Card *new_card = new Card;
    (*new_card).init(*b, *a);

    int card_type = INT_MAX;
    int *t = &card_type;
    wchar_t card_suit = ' ';
    wchar_t *s = &card_suit;
    (*new_card).get(*t, *s);
    // std::wcout << card_suit << std::endl;
    
    switch(card_suit){
        case 'S': 
            std::wcout << L"Card: " << L"Spades" << ' ';
            break;
        case 'C': 
            std::wcout << L"Card: " << L"Clubs" << ' ';
            break;
        case 'H': 
            std::wcout << L"Card: " << L"Hearts" << ' ';
            break;
        case 'D': 
            std::wcout << L"Card: " << L"Diamonds" << ' ';
            break;
        default:
            std::wcout << L"Error" << std::endl;
            exit(EXIT_FAILURE);
    }
    
    if (card_type >= 2 && card_type <= 10){
        std::wcout << card_type << std::endl;
    }
    else {
        switch(card_type){
            case 11: 
                std::wcout << L"Jack" << std::endl;
                break;
            case 12: 
                std::wcout << L"Queen" << std::endl;
                break;
            case 13: 
                std::wcout << L"King" << std::endl;
                break;
            case 14: 
                std::wcout << L"Ace" << std::endl;
                break;
            default:
                std::wcout << L"Error" << std::endl;
                exit(EXIT_FAILURE);
        };

    }
}

int main(){
    using namespace std;

    int n = 10;
    for (int i = 0; i < n; i++){
        random_card();
    }
    system("pause");
    return 0;
}