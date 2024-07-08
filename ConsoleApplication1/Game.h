#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
class Game {



public:

    static void startGame(Player& player, Player& dealer, Deck& deck);
    static void showScore(Player& player, string Name);
    static void Double(Player& player, Player& dealer, Deck &deck);
    static void DoubleForSplit(Player& player, Player& dealer, Deck& deck, string choiseHand);
    static void ShowStatistic(Player& player);
    static void showSplitScore(Player& player, string choiseHand);
    static void ShowFirstScore(Player& dealer);
    static void CheckDraw(Player& player, bool Double);
    static void CheckWin(Player& player, bool Double);
    static bool CheckBet(Player& player);
    static void DealerAddCards(Player &player, Player& dealer, Deck &deck);
    static void checkCloseWins(Player& player, Player& dealer);
    static bool CheckBlackJack(Player& player, Player& dealer, bool flag2);
    static void isLoss(Player& player, Player& dealer, bool Double);
    static void isLoss(Player& player, Player& dealer, bool Double, bool Double1);
    static void AddCardForPlayer(Player& player, Deck& deck, string choiseHand);
};
#endif
