#include "Game.h"
    void Game::ShowFirstScore(Player& dealer)
    {
        if (dealer.getLeftHandScore() != 21)
        {
            cout << "Карты Дилера: {";
            dealer.ShowFirstCard();
            cout << " Скрытая карта " << "} " << endl;
            cout << "Счёт дилера : " << dealer.getFirstCardScore() << endl;
        }
        else
            showScore(dealer, "d");
    }
    void Game::startGame(Player& player, Player& dealer, Deck& deck)
    {
        AddCardForPlayer(player, deck, "left");
        AddCardForPlayer(player, deck, "left");
        showScore(player, "p");


        dealer.addLeftCards(deck.getRandomCard());
        dealer.addLeftCards(deck.getRandomCard());
        ShowFirstScore(dealer);
    }
    void Game::showScore(Player& player, string Name)
    {
        string result = Name == "p" ? "Игрока " : "Дилера";
        cout << "Карты " << result << ": {";
        player.showLeftHand();
        cout << "}";
        cout << endl;
        cout << "Счёт " << result << ": " << player.getLeftHandScore() << endl;
    }
    void Game::showSplitScore(Player& player, string choiseHand)
    {
        if (choiseHand == "left")
        {
            cout << "Карты Игрока в левой руке" << ": {";
            player.showLeftHand();
            cout << "}";
            cout << endl;
            cout << "Счёт в левой руке: " << player.getLeftHandScore() << endl;
        }
        else if (choiseHand == "right")
        {
            cout << "Карты Игрока в правой руке" << ": {";
            player.showRightHand();
            cout << "}";
            cout << endl;
            cout << "Счёт в правой руке: " << player.getRightHandScore() << endl;
        }
    }
    void Game::DealerAddCards(Player &player, Player& dealer, Deck &deck)
    {
        while (dealer.getLeftHandScore() < 17)
        {
            dealer.addLeftCards(deck.getRandomCard());
            Game::showScore(dealer, "d");
        }
    }
    void Game::AddCardForPlayer(Player& player, Deck& deck, string choiseHand)
    {
        if (choiseHand == "left")
        {

            player.addLeftCards(deck.getRandomCard());
            player.setLeftStepsCounter(player.getLeftStepsCounter() + 1);
        }
        else
        {
            player.addRightCards(deck.getRandomCard());
            player.setRightStepsCounter(player.getRightStepsCounter() + 1);
        }
    }
    void Game::Double(Player& player,Player &dealer, Deck &deck)
    {
        if (CheckBet(player))
        {
            AddCardForPlayer(player, deck, "left");
            showScore(player, "p");
            showScore(dealer, "d");
            while (dealer.getLeftHandScore() < 17)
            {
                dealer.addLeftCards(deck.getRandomCard());
                showScore(dealer, "d");
            }
            isLoss(player, dealer, Double);
        }
    }
    bool Game::CheckBet(Player& player)
    {
        if (player.getChips() - player.getInputChips() < 0)
        {
            cout << "Нельзя сделать дабл, баланс не может быть меньше 0 фишек" << endl;
            return false;
        }
        else
        {
            player.setChips(player.getChips() - player.getInputChips());
            return true;
        }
    }
    void Game::DoubleForSplit(Player& player, Player& dealer, Deck& deck, string choiseHand)
    {
            if (choiseHand == "left")
            {
                AddCardForPlayer(player, deck, "left");
                showSplitScore(player, "left");
            }
            else if (choiseHand == "right")
            {
                AddCardForPlayer(player, deck, "right");
                showSplitScore(player, "right");
                showScore(dealer, "d");
                while (dealer.getLeftHandScore() < 17)
                {
                    dealer.addLeftCards(deck.getRandomCard());
                    showScore(dealer, "d");
                }
            }
    }
        void Game::ShowStatistic(Player& player)
        {
            if (player.getNumberOfGames() == 0)
            cout << "У Вас ещё нету статистики, сыграйте 1 игру, чтобы смотреть свою статистику" << endl;
             else
            {
            cout << "Максимальное число карт в левой руке:                        " << player.getMaxLeftStepsCounter() << endl;
            cout << "Максимальное число карт в правой руке:                       " << player.getMaxRightStepsCounter() << endl;
            cout << "Максимальное число карт в двух руках :                       " << player.getMaxSumStepsCounter() << endl;
            cout << "Максимальное количество фишек:                               " << player.getMaxChips() << endl;
            cout << "Текущее количество фишек:                                    " << player.getChips() << endl;
            cout << "Количество побед:                                            " << player.getVictorys()<< endl;
            cout << "Количество поражений:                                        " << player.getLoses()<< endl;
            cout << "Количество ничьих:                                           " << player.getDrawsCounter()<< endl;
            cout << "Количество побед Блекджеком:                                 " << player.getVictorysByBlackJack() << endl;
            cout << "Количество поражений из-за Блекджека:                        " << player.getLoosesByBlackJack() << endl;
            cout << "Количество игр на волоске(у игрока счёт на 1 больше дилера): " << player.getCloseWins() << endl;
            cout << "Количество сыгранных игр:                                    " << player.getNumberOfGames() << endl;
            }
        }
    void Game::isLoss(Player& player, Player& dealer, bool Double)
    {
        if (player.getLeftHandScore() > 21)
        {
            cout << "Игрок перебрал карты, дилер победил" << endl;
            player.addLoses();
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "Дилер перебрал карты, игрок победил" << endl;
            CheckWin(player, Double);
            player.addVictorys();
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore())
        {
            cout << "Счёт игрока больше, игрок победил" << endl;
            if (player.getLeftHandScore() - dealer.getLeftHandScore() == 1)
                player.addCloseWins();
            CheckWin(player, Double);
            player.addVictorys();
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore())
        {
            cout << "Счёт дилера больше, дилер победил" << endl;
            player.addLoses();
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore())
        {
            cout << "Ничья!" << endl;
            player.addDrawsCounter();
            CheckDraw(player, Double);
        }
    }
    void Game::CheckDraw(Player& player, bool Double)
    {
        if (Double)
            player.setChips(player.getChips() + player.getInputChips() * 2);
        else
            player.setChips(player.getChips() + player.getInputChips());
    }
    void Game::CheckWin(Player& player, bool Double)
    {
        if (Double)
            player.setChips(player.getChips() + player.getInputChips() * 4);
        else
            player.setChips(player.getChips() + player.getInputChips() * 2);
    }
    void Game::checkCloseWins(Player &player, Player &dealer)
    {
        if (player.getLeftHandScore() - dealer.getLeftHandScore() == 1
            || player.getRightHandScore() - dealer.getLeftHandScore() == 1)
            player.addCloseWins();
    }
    void Game::isLoss(Player& player, Player& dealer, bool Double, bool Double1)
    {
        if (player.getLeftHandScore() > 21 && player.getRightHandScore() > 21)
        {
            cout << "Игрок Перебрал карты, дилер победил" << endl;
            player.addLoses();
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "Дилер перебрал карты, игрок победил" << endl;
            player.addVictorys();
            CheckWin(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > 21)//Win Left, Loose Right
        {
            cout << "Ничья!" << endl;
            player.addDrawsCounter();
            CheckWin(player, Double);
        }
        else if (player.getRightHandScore() > dealer.getLeftHandScore() && player.getLeftHandScore() < dealer.getLeftHandScore()
            || player.getRightHandScore() > dealer.getLeftHandScore() && player.getLeftHandScore() > 21)//Loose Left, Win Right
        {
            cout << "Ничья!" << endl;
            player.addDrawsCounter();
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())// draw
        {
            cout << "Ничья!" << endl;
            player.addDrawsCounter();
            CheckDraw(player, Double);
            CheckDraw(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "Игрок победил!" << endl;
            checkCloseWins(player, dealer);
            player.addVictorys();
            CheckWin(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "Игрок победил" << endl;
            checkCloseWins(player, dealer);
            player.addVictorys();
            CheckWin(player, Double);
            CheckDraw(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "Игрок победил" << endl;
            checkCloseWins(player, dealer);
            player.addVictorys();
            CheckDraw(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "Игрок проиграл" << endl;
            player.addLoses();
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore())
        {
            cout << "Игрок проиграл" << endl;
            player.addLoses();
        }
    }
    bool Game::CheckBlackJack(Player& player, Player& dealer) {
        if (player.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2)
        {
            showScore(dealer, "d");
            cout << "У игрока блэкджэк!" << endl;
            player.setChips(player.getChips() + player.getInputChips() * 3);
            player.addVictorysByBlackJack();
            player.addVictorys();
            return true;
        }
        else if (dealer.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2) {
            cout << "У дилера блэкджэк!" << endl;
            player.addLoosesByBlackJack();
            player.addLoses();
            return true;
        }
        return false;
    }
