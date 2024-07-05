#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "Card.h"

class Player {
    vector<Card> Lefthand;
    vector<Card> RightHand;
    int score = 0;
    int chips = 20;
    int inputChips = 0;
    int LeftStepsCounter = 0;
    int RightStepsCounter = 0;
    int MaxStepsCounter = 0;
    int MaxChips = chips;
    int MaxScore = 0;
    int VictorysByBlackJack = 0;
    int LoosesByBlackJack = 0;
    int NumberOfGames = 0;
public:
    bool CheckOnSplit(Player &player);
    void Split(Player& player, Player& dealer, Deck& deck);
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
    void clearHands();
    void setChips(int inputChips);
    int  getChips();
    void setInputChips(int InputChips);
    int  getInputChips();
    void ShowFirstCard();
    int  getFirstCardScore();
    //static void isLoss(Player& player, Player& dealer, bool Double);
    void showLeftHand();
    void showRightHand();
    void showChips();
    void addLeftCards(Card card);
    void addRightCards(Card card);
    int  getLeftHandScore();
    int  getRightHandScore();
    void setLeftStepsCounter(int counter);
    void setRightStepsCounter(int counter);
    int  getLeftStepsCounter();
    int  getRightStepsCounter();
    int SumStepsCounter();
};
#endif
