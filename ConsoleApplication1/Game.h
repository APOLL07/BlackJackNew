#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
class Game {



public:

    static void startGame(Player& player, Player& dealer, Deck& deck);
    static void showScore(Player& player, string Name);
    static void DoubleLeft(Player& player, Player& dealer, Deck &deck, bool Double);
    static void DoubleRight(Player& player, Player& dealer, Deck &deck, bool Double);
    static void ShowStatistic(Player& player);
    static void showRightScore(Player& player);
    static void showLeftScore(Player& player);
    static bool CheckBlackJack(Player& player, Player& dealer, bool flag2);
    static void isLoss(Player& player, Player& dealer, bool Double);
    //static void isLossLeft(Player& player, Player& dealer, bool Double);
    //static void isLossRight(Player& player, Player& dealer, bool Double);
    static void isLoss(Player& player, Player& dealer, bool Double, bool Double1);
    //void Split(Player& player);
};
#endif
