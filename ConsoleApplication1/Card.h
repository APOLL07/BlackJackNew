#pragma once
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>
#include <random>
using namespace std;
class Card {
    int rank;
    int suit;
public:
    enum Rank {
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };
    enum Suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    Card(Rank rank, Suit suit);
    int getValue();
    string getRank();
    string getSuit();
    void setValue(int inputValue);
    void showCard();
};
#endif
