#include "Game.h"
    void Game::startGame(Player& player, Player& dealer, Deck& deck)
    {
        player.addCard(deck.getRandomCard());
        player.setStepsCounter(player.getStepsCounter() + 1);
        player.addCard(deck.getRandomCard());
        player.setStepsCounter(player.getStepsCounter() + 1);
        showScore(player, "p");


        dealer.addCard(deck.getRandomCard());
        dealer.addCard(deck.getRandomCard());
        if (dealer.getScore() != 21)
        {
            cout << "Карта дилера: {";
            dealer.ShowFirstCard();
            cout << "} Счёт дилера:" << dealer.getFirstCardScore() << endl;
        }
        else
            showScore(dealer, "d");
    }
    void Game::showScore(Player& player, string Name)
    {
        string result = Name == "p" ? "Игрока " : "Дилера*";
        cout << "Карты " << result << ": {";
        player.showHand();
        cout << " } Score:" << player.getScore() << endl;
    }