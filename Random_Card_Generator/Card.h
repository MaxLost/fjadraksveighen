#pragma once
class Card {
private:
    int type;
    int suit;
public:
    Card();
    void SetProperties(int t, int s);
    void GetProperties(int& t, int& s);
    ~Card();
};