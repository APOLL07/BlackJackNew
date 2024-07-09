#include "Game.h"
    void Game::ShowFirstScore(Player& dealer)
    {
        if (dealer.getLeftHandScore() != 21)
        {
            cout << "����� ������: {";
            dealer.ShowFirstCard();
            cout << " ������� ����� " << "} " << endl;
            cout << "���� ������ : " << dealer.getFirstCardScore() << endl;
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
        string result = Name == "p" ? "������ " : "������";
        cout << "����� " << result << ": {";
        player.showLeftHand();
        cout << "}";
        cout << endl;
        cout << "���� " << result << ": " << player.getLeftHandScore() << endl;
    }
    void Game::showSplitScore(Player& player, string choiseHand)
    {
        if (choiseHand == "left")
        {
            cout << "����� ������ � ����� ����" << ": {";
            player.showLeftHand();
            cout << "}";
            cout << endl;
            cout << "���� � ����� ����: " << player.getLeftHandScore() << endl;
        }
        else if (choiseHand == "right")
        {
            cout << "����� ������ � ������ ����" << ": {";
            player.showRightHand();
            cout << "}";
            cout << endl;
            cout << "���� � ������ ����: " << player.getRightHandScore() << endl;
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
            cout << "������ ������� ����, ������ �� ����� ���� ������ 0 �����" << endl;
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
        if (CheckBet(player))
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
    }
    //void Game::ShowStatistic(Player& player)
    //{
    //    if (player.getNumberOfGames() == 0)
    //        cout << "� ��� ��� ���� ����������, �������� 1 ����, ����� �������� ���� ����������" << endl;
    //    else
    //    {
    //        cout << "������������ ����� ���� � ����� ����:  " << player.getMaxLeftStepsCounter() << endl;
    //        cout << "������������ ����� ���� � ������ ����: " << player.getMaxRightStepsCounter() << endl;
    //        cout << "������������ ����� ���� � ���� ����� : " << player.getMaxSumStepsCounter() << endl;
    //        cout << "������������ ���������� �����: " << player.getMaxChips() << endl;
    //        cout << "���������� �����: " << player.getVictorys()<< endl;
    //        cout << "���������� ���������: " << player.getLoses()<< endl;
    //        cout << "���������� ������: " << player.getDrawsCounter()<< endl;
    //        cout << "���������� ����� ����������: " << player.getVictorysByBlackJack() << endl;
    //        cout << "���������� ��������� ��-�� ���������: " << player.getLoosesByBlackJack() << endl;
    //        cout << "���������� ��� �� �������(� ������ ���� �� 1 ������ ������):" << player.getCloseWins() << endl;
    //        cout << "���������� ��������� ���: " << player.getNumberOfGames() << endl;
    //    }
    //}
        void Game::ShowStatistic(Player& player)
        {
       /* if (player.getNumberOfGames() == 0)
            cout << "� ��� ��� ���� ����������, �������� 1 ����, ����� �������� ���� ����������" << endl;
             else
            {*/
            cout << "������������ ����� ���� � ����� ����:                        " << player.getMaxLeftStepsCounter() << endl;
            cout << "������������ ����� ���� � ������ ����:                       " << player.getMaxRightStepsCounter() << endl;
            cout << "������������ ����� ���� � ���� ����� :                       " << player.getMaxSumStepsCounter() << endl;
            cout << "������������ ���������� �����:                               " << player.getMaxChips() << endl;
            cout << "���������� �����:                                            " << player.getVictorys()<< endl;
            cout << "���������� ���������:                                        " << player.getLoses()<< endl;
            cout << "���������� ������:                                           " << player.getDrawsCounter()<< endl;
            cout << "���������� ����� ����������:                                 " << player.getVictorysByBlackJack() << endl;
            cout << "���������� ��������� ��-�� ���������:                        " << player.getLoosesByBlackJack() << endl;
            cout << "���������� ��� �� �������(� ������ ���� �� 1 ������ ������): " << player.getCloseWins() << endl;
            cout << "���������� ��������� ���:                                    " << player.getNumberOfGames() << endl;
            /*}*/
        }
    void Game::isLoss(Player& player, Player& dealer, bool Double)
    {
        player.setNumberOfGames(player.getNumberOfGames() + 1);
        if (player.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            player.setLoses(player.getLoses() + 1);
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            CheckWin(player, Double);
            player.setVictorys(player.getVictorys() + 1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            if (player.getLeftHandScore() - dealer.getLeftHandScore() == 1)
                player.setCloseWins(player.getCloseWins() + 1);
            CheckWin(player, Double);
            player.setVictorys(player.getVictorys() + 1);
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            player.setLoses(player.getLoses() + 1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore())
        {
            cout << "�����!" << endl;
            player.setDrawsCounter(player.getDrawsCounter() + 1);
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
            player.setCloseWins(player.getCloseWins() + 1);
    }
    void Game::isLoss(Player& player, Player& dealer, bool Double, bool Double1)
    {
        player.setNumberOfGames(player.getNumberOfGames() + 1);
        if (player.getLeftHandScore() > 21 && player.getRightHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            player.setLoses(player.getLoses() + 1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "����� �������!" << endl;
            checkCloseWins(player, dealer);
            player.setVictorys(player.getVictorys() + 1);
            CheckWin(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore()
            || player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore()
            || player.getLeftHandScore() > 21 && player.getRightHandScore() > dealer.getLeftHandScore() 
            || player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > 21)
        {
            cout << "�����!" << endl;
            player.setDrawsCounter(player.getDrawsCounter() + 1);
            CheckDraw(player, Double);
            CheckDraw(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore()
            || player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "����� �������" << endl;
            checkCloseWins(player, dealer);
            player.setVictorys(player.getVictorys() + 1);
            CheckDraw(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "����� ��������" << endl;
            player.setLoses(player.getLoses() + 1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore()
            || player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "����� �������" << endl;
            checkCloseWins(player, dealer);
            player.setVictorys(player.getVictorys() + 1);
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            player.setLoses(player.getLoses() + 1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            checkCloseWins(player, dealer);
            player.setVictorys(player.getVictorys() + 1);
            CheckWin(player, Double);
            CheckWin(player, Double1);
        }
    }
    bool Game::CheckBlackJack(Player& player, Player& dealer, bool flag2) {
        if (player.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2)
        {
            showScore(dealer, "d");
            cout << "� ������ ��������!" << endl;
            player.setChips(player.getChips() + player.getInputChips() * 3);
            player.setVictorysByBlackJack(player.getVictorysByBlackJack() + 1);
            return true;
        }
        else if (dealer.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2) {
            cout << "� ������ ��������!" << endl;
            player.setLoosesByBlackJack(player.getLoosesByBlackJack() + 1);
            return true;
        }
        return false;
    }
