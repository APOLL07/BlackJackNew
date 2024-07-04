#pragma once
#ifndef DECK_H
#define DECK_H
#include "Card.h"
class Deck {
    vector<Card> deck;
    int FillRandomNumber(int Start, int End);
public:
    Deck();
    
    Card getRandomCard();
};
#endif 