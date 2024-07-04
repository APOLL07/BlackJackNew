#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
class Player {
    vector<Card> hand;
    int score = 0;
    int chips = 20;
    int inputChips = 0;
    int stepsCounter = 0;
public:
    void clearHand();
    void setChips(int inputChips);
    int getChips();
    void setInputChips(int InputChips);
    int getInputChips();
    void ShowFirstCard();
    int getFirstCardScore();
    static void isLoss(Player& player, Player& dealer);
    void showHand();
    void showChips();
    void addCard(Card card);
    int getScore();
    void setStepsCounter(int counter);
    int getStepsCounter();
};
#endif
