#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
class Game {



public:

    static void startGame(Player& player, Player& dealer, Deck& deck);
    static void showScore(Player& player, string Name);
    static void Double(Player& player, Player& dealer, Deck &deck, bool Double);
    static void ShowStatistic(Player& player);
};
#endif
