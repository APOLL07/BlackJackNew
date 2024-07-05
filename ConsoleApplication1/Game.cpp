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
            cout << "����� ������: {";
            dealer.ShowFirstCard();
            cout <<" ������� ����� " << "} ���� ������:" << dealer.getFirstCardScore()  << endl;
        }
        else
            showScore(dealer, "d");
    }
    void Game::showScore(Player& player, string Name)
    {
        string result = Name == "p" ? "������ " : "������*";
        cout << "����� " << result << ": {";
        player.showLeftHand();
        cout << " } Score:" << player.getLeftHandScore() << endl;
    }
    void Game::showLeftScore(Player& player)
    {
        cout << "����� ������ � ����� ����" << ": {";
        player.showLeftHand();
        cout << "}";
        cout << endl;
        cout << "���� � ����� ����:" << player.getLeftHandScore() << endl;
    }
    void Game::showRightScore(Player& player)
    {
        cout << "����� ������ � ������ ����" << ": {";
        player.showRightHand();
        cout << "}";
        cout << endl;
        cout << "���� � ������ ���� : " << player.getRightHandScore() << endl;
    }
    void Game::DoubleLeft(Player& player,Player &dealer, Deck &deck, bool Double)
    {
        if (player.getChips() - player.getInputChips() < 0)
            cout << "������ ������� ����, ������ �� ����� ���� ������ 0 �����" << endl;
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
            cout << "������ ������� ����, ������ �� ����� ���� ������ 0 �����" << endl;
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
            cout << "� ��� ��� ���� ����������, �������� 1 ����, ����� �������� ���� ����������" << endl;
        else
        {
            cout << "������������ ����� ���� � ����:       " << player.getMaxStepsCounter() << endl;
            cout << "������������ ���������� �����:        " << player.getMaxChips() << endl;
            cout << "������������ ����:                    " << player.getMaxScore() << endl;
            cout << "���������� ����� ����������:          " << player.getVictorysByBlackJack() << endl;
            cout << "���������� ��������� ��-�� ���������: " << player.getLoosesByBlackJack() << endl;
            cout << "���������� ��������� ���              " << player.getNumberOfGames() << endl;
        }
    }
    void Game::isLoss(Player& player, Player& dealer, bool Double)
    {
        if (player.getLeftHandScore() > 21)
            cout << "����� �������� �����, ����� �������" << endl;
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.getLeftHandScore() > dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.getLeftHandScore() < dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
        }
        else if (player.getLeftHandScore() == dealer.getLeftHandScore())
        {
            cout << "�����!" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 2);
            else
                player.setChips(player.getChips() + player.getInputChips());
        }
    }
    //void Game::isLossLeft(Player& player, Player& dealer, bool Double)
    //{
    //    if (player.getLeftHandScore() > 21)
    //        cout << "����� �������� ����� � ����� ����" << endl;
    //    else if (player.getLeftHandScore() > dealer.getLeftHandScore())
    //    {
    //        cout << "���� ������ � ����� ���� ������" << endl;
    //        if (Double)
    //            player.setChips(player.getChips() + player.getInputChips() * 4);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //    }
    //    else if (player.getLeftHandScore() == dealer.getLeftHandScore())
    //    {
    //        cout << "����� � ����� ����" << endl;
    //        if (Double)
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips());
    //    }
    //}
    //void Game::isLossRight(Player& player, Player& dealer, bool Double1)
    //{
    //    if (player.getRightHandScore() > 21)
    //        cout << "����� �������� ����� � ������ ����" << endl;
    //    else if (player.getRightHandScore() > dealer.getRightHandScore())
    //    {
    //        cout << "���� ������ ������ � ������ ����, ��� ���� ������" << endl;
    //        if (Double1)
    //            player.setChips(player.getChips() + player.getInputChips() * 4);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //    }
    //    else if (player.getRightHandScore() == dealer.getRightHandScore())
    //    {
    //        cout << "����� � ������ ����" << endl;
    //        if (Double1)
    //            player.setChips(player.getChips() + player.getInputChips() * 2);
    //        else
    //            player.setChips(player.getChips() + player.getInputChips());
    //    }
    //}
    void Game::isLoss(Player& player, Player& dealer, bool Double, bool Double1)
    {
        if (player.getLeftHandScore() > 21 && player.getRightHandScore() > 21)
            cout << "����� �������� �����, ����� �������" << endl;
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "����� �������!" << endl;
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
            cout << "�����!" << endl;
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
            cout << "����� �������" << endl;
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
            cout << "����� ��������" << endl;
        }
        else if (dealer.getLeftHandScore() > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
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
            cout << "���� ������ ������, ����� �������" << endl;
        else if (player.getLeftHandScore() > dealer.getLeftHandScore() && player.getRightHandScore() > dealer.getLeftHandScore())
        {
            cout << "���� ������ ������, ����� �������" << endl;
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
