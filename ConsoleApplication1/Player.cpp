#include "Player.h"
    void Player::clearHand()
    {
        hand.clear();
    }
    void Player::setChips(int inputChips)
    {
        chips = inputChips;
    }
    int Player::getChips()
    {
        return chips;
    }
    void Player::setInputChips(int InputChips)
    {
        inputChips = InputChips;
    }
    int Player::getInputChips()
    {
        return inputChips;
    }
    void Player::ShowFirstCard()
    {
        hand[0].showCard();
    }
    int Player::getFirstCardScore()
    {
        return hand[0].getValue();
    }
    void Player::isLoss(Player& player, Player& dealer)
    {
        if (player.score > 21)
            cout << "����� �������� �����, ����� �������" << endl;
        else if (dealer.score > 21)
        {
            cout << "����� �������� �����, ����� �������" << endl;
            player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.score > dealer.score)
        {
            cout << "���� ������ ������, ����� �������" << endl;
            player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.score < dealer.score)
            cout << "���� ������ ������, ����� �������" << endl;
        else if (player.getScore() == dealer.getScore())
        {
            cout << "�����!" << endl;
            player.setChips(player.getChips() + player.getInputChips());
        }
    }
    void Player::showHand()
    {
        for (auto& card : hand) {
            card.showCard();
        }
    }
    void Player::showChips()
    {
        cout << "���� �����: " << chips << endl;
    }
    void Player::addCard(Card card) {
        hand.push_back(card);
    }
    int Player::getScore() {
        score = 0;
        for (auto& elem : hand)
        {
            if (elem.getValue() == 11 && score + elem.getValue() > 21)//TODO: �������� ��� ����� ���������� � ����� �� �� ��������
            {
                score += 1;
            }
            else
                score += elem.getValue();
        }
        return score;
    }
    void Player::setStepsCounter(int counter)
    {
        stepsCounter = counter;
    }
    int Player::getStepsCounter()
    {
        return stepsCounter;
    }