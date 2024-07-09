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
            cout << "� ��� ��� ���� ����������, �������� 1 ����, ����� �������� ���� ����������" << endl;
             else
            {
            cout << "������������ ����� ���� � ����� ����:                        " << player.getMaxLeftStepsCounter() << endl;
            cout << "������������ ����� ���� � ������ ����:                       " << player.getMaxRightStepsCounter() << endl;
            cout << "������������ ����� ���� � ���� ����� :                       " << player.getMaxSumStepsCounter() << endl;
            cout << "������������ ���������� �����:                               " << player.getMaxChips() << endl;
            cout << "������� ���������� �����:                                    " << player.getChips() << endl;
            cout << "���������� �����:                                            " << player.getVictorys()<< endl;
            cout << "���������� ���������:                                        " << player.getLoses()<< endl;
            cout << "���������� ������:                                           " << player.getDrawsCounter()<< endl;
            cout << "���������� ����� ����������:                                 " << player.getVictorysByBlackJack() << endl;
            cout << "���������� ��������� ��-�� ���������:                        " << player.getLoosesByBlackJack() << endl;
            cout << "���������� ��� �� �������(� ������ ���� �� 1 ������ ������): " << player.getCloseWins() << endl;
            cout << "���������� ��������� ���:                                    " << player.getNumberOfGames() << endl;
            }
        }
    void Game::isLoss(Player& player, Player& dealer, bool Double)
    {
        if (player.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            player.addLoses();
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            CheckWin(player, Double);
            player.addVictorys();
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            if (player.getLeftHandScore() - dealer.getLeftHandScore() == 1)
                player.addCloseWins();
            CheckWin(player, Double);
            player.addVictorys();
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            player.addLoses();
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore())
        {
            cout << "�����!" << endl;
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
            cout << "����� �������� �����, ����� �������" << endl;
            player.addLoses();
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            player.addVictorys();
            CheckWin(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > 21)//Win Left, Loose Right
        {
            cout << "�����!" << endl;
            player.addDrawsCounter();
            CheckWin(player, Double);
        }
        else if (player.getRightHandScore() > dealer.getLeftHandScore() && player.getLeftHandScore() < dealer.getLeftHandScore()
            || player.getRightHandScore() > dealer.getLeftHandScore() && player.getLeftHandScore() > 21)//Loose Left, Win Right
        {
            cout << "�����!" << endl;
            player.addDrawsCounter();
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())// draw
        {
            cout << "�����!" << endl;
            player.addDrawsCounter();
            CheckDraw(player, Double);
            CheckDraw(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "����� �������!" << endl;
            checkCloseWins(player, dealer);
            player.addVictorys();
            CheckWin(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "����� �������" << endl;
            checkCloseWins(player, dealer);
            player.addVictorys();
            CheckWin(player, Double);
            CheckDraw(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "����� �������" << endl;
            checkCloseWins(player, dealer);
            player.addVictorys();
            CheckDraw(player, Double);
            CheckWin(player, Double1);
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore()
            || player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() == dealer.getLeftHandScore())
        {
            cout << "����� ��������" << endl;
            player.addLoses();
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore() && player.getRightHandScore() < dealer.getLeftHandScore())
        {
            cout << "����� ��������" << endl;
            player.addLoses();
        }
    }
    bool Game::CheckBlackJack(Player& player, Player& dealer) {
        if (player.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2)
        {
            showScore(dealer, "d");
            cout << "� ������ ��������!" << endl;
            player.setChips(player.getChips() + player.getInputChips() * 3);
            player.addVictorysByBlackJack();
            player.addVictorys();
            return true;
        }
        else if (dealer.getLeftHandScore() == 21 && player.getLeftStepsCounter() == 2) {
            cout << "� ������ ��������!" << endl;
            player.addLoosesByBlackJack();
            player.addLoses();
            return true;
        }
        return false;
    }
