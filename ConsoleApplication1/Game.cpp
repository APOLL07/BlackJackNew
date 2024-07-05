#include "Game.h"
    void Game::startGame(Player& player, Player& dealer, Deck& deck)
    {
        player.addLeftCards(deck.getRandomCard());
        player.setLeftStepsCounter(player.getLeftStepsCounter() + 1);
        player.addLeftCards(deck.getRandomCard());
        player.setLeftStepsCounter(player.getLeftStepsCounter() + 1);
        showScore(player, "p");


        dealer.addLeftCards(deck.getRandomCard());
        dealer.addLeftCards(deck.getRandomCard());
        if (dealer.getLeftHandScore() != 21)
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
        player.showLeftHand();
        cout << " } Score:" << player.getLeftHandScore() << endl;
    }
    void Game::showLeftScore(Player& player)
    {
        cout << "Карты Игрока в левой руке" << ": {";
        player.showLeftHand();
        cout << "}";
        cout << endl;
        cout << "Счёт в левой руке:" << player.getLeftHandScore() << endl;
    }
    void Game::showRightScore(Player& player)
    {
        cout << "Карты Игрока в правой руке" << ": {";
        player.showRightHand();
        cout << "}";
        cout << endl;
        cout << "Счёт в правой руке : " << player.getRightHandScore() << endl;
    }
    void Game::DoubleLeft(Player& player,Player &dealer, Deck &deck, bool Double)
    {
        if (player.getChips() - player.getInputChips() < 0)
            cout << "Нельзя сделать дабл, баланс не может быть меньше 0 фишек" << endl;
        else
        {
            player.setChips(player.getChips() - player.getInputChips());
            player.addLeftCards(deck.getRandomCard());
            player.setLeftStepsCounter(player.getLeftStepsCounter() + 1);
            showLeftScore(player);
            //Game::isLossLeft(player, dealer, Double);
        }
    }
    void Game::DoubleRight(Player& player, Player& dealer, Deck& deck, bool Double)
    {
        if (player.getChips() - player.getInputChips() < 0)
            cout << "Нельзя сделать дабл, баланс не может быть меньше 0 фишек" << endl;
        else
        {
            player.setChips(player.getChips() - player.getInputChips());
            player.addRightCards(deck.getRandomCard());
            player.setRightStepsCounter(player.getRightStepsCounter() + 1);
            showRightScore(player);
            while (dealer.getLeftHandScore() < 17)
            {
                dealer.addLeftCards(deck.getRandomCard());
                Game::showScore(dealer, "d");
            }
            //Game::isLossRight(player, dealer, Double);
        }
    }
    void Game::ShowStatistic(Player& player)
    {
        if (player.getMaxScore() == 0)
            cout << "У Вас ещё нету статистики, сыграйте 1 игру, чтобы смотреть свою статистику" << endl;
        else
        {
            cout << "Максимальное число карт в руке:       " << player.getMaxStepsCounter() << endl;
            cout << "Максимальное количество фишек:        " << player.getMaxChips() << endl;
            cout << "Максимальный счёт:                    " << player.getMaxScore() << endl;
            cout << "Количество побед Блекджеком:          " << player.getVictorysByBlackJack() << endl;
            cout << "Количество поражений из-за Блекджека: " << player.getLoosesByBlackJack() << endl;
            cout << "Количество сыгранных игр              " << player.getNumberOfGames() << endl;
        }
    }
    void Game::isLoss(Player& player, Player& dealer, bool Double)
    {
        if (player.getLeftHandScore() > 21)
            cout << "Игрок перебрал карты, дилер победил" << endl;
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "Дилер перебрал карты, игрок победил" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore())
        {
            cout << "Счёт игрока больше, игрок победил" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore())
        {
            cout << "Счёт дилера больше, дилер победил" << endl;
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore())
        {
            cout << "Ничья!" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 2);
            else
                player.setChips(player.getChips() + player.getInputChips());
        }
    }
    //void Game::isLossLeft(Player& player, Player& dealer, bool Double)
    //{
    //    if (player.getLeftHandScore() > 21)
    //        cout << "Игрок перебрал карты в левой руке" << endl;
    //    else if (player.getLeftHandScore() > dealer.getLeftHandScore())
    //    {
    //        cout << "Счёт игрока в левой руке больше" << endl;
    //        if (Double)
    //            player.setChips(player.getChips() + player.getInputChips() * 4);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //    }
    //    else if (player.getLeftHandScore() == dealer.getLeftHandScore())
    //    {
    //        cout << "Ничья в левой руке" << endl;
    //        if (Double)
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips());
    //    }
    //}
    //void Game::isLossRight(Player& player, Player& dealer, bool Double1)
    //{
    //    if (player.getRightHandScore() > 21)
    //        cout << "Игрок перебрал карты в правой руке" << endl;
    //    else if (player.getRightHandScore() > dealer.getRightHandScore())
    //    {
    //        cout << "Счёт игрока больше в правой руке, чем счёт дилера" << endl;
    //        if (Double1)
    //            player.setChips(player.getChips() + player.getInputChips() * 4);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //    }
    //    else if (player.getRightHandScore() == dealer.getRightHandScore())
    //    {
    //        cout << "Ничья в правой руке" << endl;
    //        if (Double1)
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips());
    //    }
    //}
    void Game::isLoss(Player& player, Player& dealer, bool Double, bool Double1)
    {
        if (player.getLeftHandScore() > 21 && player.getRightHandScore() > 21)
            cout << "Игрок Перебрал карты, дилер победил" << endl;
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "Игрок победил!" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
            if (Double1)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);

        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore()
            || player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "Ничья!" << endl;
             if (Double)
                 player.setChips(player.getChips() + player.getInputChips() * 2);
             else
                 player.setChips(player.getChips() + player.getInputChips());
             if (Double1)
                player.setChips(player.getChips() + player.getInputChips() * 2);
            else
                player.setChips(player.getChips() + player.getInputChips());
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore()
            || player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "Игрок победил" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 2);
            else
                player.setChips(player.getChips() + player.getInputChips());
            if (Double1)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "Игрок проиграл" << endl;
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "Дилер перебрал карты, игрок победил" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
            if (Double1)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore())
            cout << "Счёт дилера больше, дилер победил" << endl;
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "Счёт игрока больше, игрок победил" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
            if (Double1)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
    }
    bool Game::CheckBlackJack(Player& player, Player& dealer, bool flag2) {
        if (player.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2)
        {
            Game::showScore(dealer, "d");
            cout << "У игрока блэкджэк!" << endl;
            player.setChips(player.getChips() + player.getInputChips() * 3);
            player.setVictorysByBlackJack(player.getVictorysByBlackJack() + 1);
            return true;
        }
        else if (dealer.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2) {
            cout << "У дилера блэкджэк!" << endl;
            player.setLoosesByBlackJack(player.getLoosesByBlackJack() + 1);
            return true;
        }
        return false;
    }
