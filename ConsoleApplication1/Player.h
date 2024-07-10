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
    int MaxLeftStepsCounter = 0;
    int MaxRightStepsCounter = 0;
    int MaxSumStepsCounter = 0;
    int LosesCounter = 0;
    int VictorysCounter = 0;
    int MaxChips = chips;
    int VictorysByBlackJack = 0;
    int CloseWins = 0;
    int LoosesByBlackJack = 0;
    int NumberOfGames = 0;
    int DrawsCounter = 0;
public:
    void addVictorys();
    int  getVictorys();
    void addLoses();
    int  getLoses();
    void addCloseWins();
    int  getCloseWins();
    bool CheckOnSplit(Player &player);
    void Split(Player& player, Player& dealer, Deck& deck);
    void addNumberOfGames();
    int  getNumberOfGames();
    void addVictorysByBlackJack();
    int  getVictorysByBlackJack();
    void addLoosesByBlackJack();
    int  getLoosesByBlackJack();
    void setMaxChips(int inputChips);
    int  getMaxChips();
    int  getDrawsCounter();
    void addDrawsCounter();
    void setMaxLeftStepsCounter(int inputsteps);
    int  getMaxLeftStepsCounter();
    void setMaxSumStepsCounter(int inputsteps);
    int  getMaxSumStepsCounter();
    void setMaxRightStepsCounter(int inputsteps);
    int  getMaxRightStepsCounter();
    void clearHands();
    void setChips(int inputChips);
    int  getChips();
    void setInputChips(int InputChips);
    int  getInputChips();
    void ShowFirstCard();
    int  getFirstCardScore();
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
    int  SumStepsCounter();
    void writeStatistics(string S) const;
    void ReadStatistics(string S);
    //void writeChipsStatistic(string S) const;
    //void readChipsStatistic(string S);
};
#endif
