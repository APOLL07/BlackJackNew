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
    int MaxStepsCounter = 0;
    int MaxChips = chips;
    int MaxScore = 0;
    int VictorysByBlackJack = 0;
    int LoosesByBlackJack = 0;
    int NumberOfGames = 0;
public:
    void setNumberOfGames(int inputgames);
    int getNumberOfGames();
    void setVictorysByBlackJack(int inputVictorys);
    int  getVictorysByBlackJack();
    void setLoosesByBlackJack(int inputLooses);
    int  getLoosesByBlackJack();
    void setMaxChips(int inputChips);
    int  getMaxChips();
    void setMaxStepsCounter(int inputsteps);
    int  getMaxStepsCounter();
    void setMaxScore(int inputscore);
    int  getMaxScore();
    void clearHand();
    void setChips(int inputChips);
    int  getChips();
    void setInputChips(int InputChips);
    int  getInputChips();
    void ShowFirstCard();
    int  getFirstCardScore();
    static void isLoss(Player& player, Player& dealer, bool Double);
    void showHand();
    void showChips();
    void addCard(Card card);
    int  getScore();
    void setStepsCounter(int counter);
    int  getStepsCounter();
};
#endif
