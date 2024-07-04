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
            cout <<" Скрытая карта " << "} Счёт дилера:" << dealer.getFirstCardScore()  << endl;
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
    void Game::Double(Player& player,Player &dealer, Deck &deck, bool Double)
    {
        Double = true;
        if (player.getChips() - player.getInputChips() < 0)
            cout << "Нельзя сделать дабл, баланс не может быть меньше 0 фишек" << endl;
        else
        {
            player.setChips(player.getChips() - player.getInputChips());
            player.addCard(deck.getRandomCard());
            player.setStepsCounter(player.getStepsCounter() + 1);
            showScore(player, "p");
            while (dealer.getScore() < 17)
            {
                dealer.addCard(deck.getRandomCard());
                Game::showScore(dealer, "d");
            }
            Player::isLoss(player, dealer, Double);
        }
    }
    void Game::ShowStatistic(Player& player)
    {
        if (player.getMaxScore() == 0)
            cout << "У Вас ещё нету статистики, сыграйте 1 игру, чтобы смотреть свою статистику" << endl;
        else
        {
            cout << "Максимальное число карт в руке: " << player.getMaxStepsCounter() << endl;
            cout << "Максимальное количество фишек:  " << player.getMaxChips() << endl;
            cout << "Максимальное счёт:              " << player.getMaxScore() << endl;
            cout << "Количество побед Блекджеком:    " << player.getVictorysByBlackJack() << endl;
            cout << "Количество поражений из-за Блекджека: " << player.getLoosesByBlackJack() << endl;
            cout << "Количество сыгранных игр        " << player.getNumberOfGames() << endl;
        }
    }