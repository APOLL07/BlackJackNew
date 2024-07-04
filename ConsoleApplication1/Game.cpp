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
        player.showHand();
        cout << " } Score:" << player.getScore() << endl;
    }
    void Game::Double(Player& player,Player &dealer, Deck &deck, bool Double)
    {
        Double = true;
        if (player.getChips() - player.getInputChips() < 0)
            cout << "������ ������� ����, ������ �� ����� ���� ������ 0 �����" << endl;
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
            cout << "� ��� ��� ���� ����������, �������� 1 ����, ����� �������� ���� ����������" << endl;
        else
        {
            cout << "������������ ����� ���� � ����: " << player.getMaxStepsCounter() << endl;
            cout << "������������ ���������� �����:  " << player.getMaxChips() << endl;
            cout << "������������ ����:              " << player.getMaxScore() << endl;
            cout << "���������� ����� ����������:    " << player.getVictorysByBlackJack() << endl;
            cout << "���������� ��������� ��-�� ���������: " << player.getLoosesByBlackJack() << endl;
            cout << "���������� ��������� ���        " << player.getNumberOfGames() << endl;
        }
    }