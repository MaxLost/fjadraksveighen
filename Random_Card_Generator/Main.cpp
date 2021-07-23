#include <iostream>
#include "RandomCardGenerator.h"
#include "Card.h"

int main(void){
    using namespace std;
    int n;
    RandomCardGenerator *Generator = new RandomCardGenerator;
    cout << "Enter amount of cards you would to generate: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        (*Generator).GenerateRandomCard();
    }
    delete Generator;
    system("pause");
    return 0;
}