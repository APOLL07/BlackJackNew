#include "Player.h"
#include "Game.h"
    void Player::setNumberOfGames(int inputgames)
    {
        NumberOfGames = inputgames;
    }
    int Player::getNumberOfGames()
    {
        return NumberOfGames;
    }
    void Player::setVictorysByBlackJack(int inputVictorys)
    {
        VictorysByBlackJack = inputVictorys;
    }
    int  Player::getVictorysByBlackJack()
    {
        return VictorysByBlackJack;
    }
    void Player::setLoosesByBlackJack(int inputLooses)
    {
        LoosesByBlackJack = inputLooses;
    }
    int Player::getLoosesByBlackJack()
    {
        return LoosesByBlackJack;
    }
    void Player::setMaxChips(int inputChips)
    {
        MaxChips = inputChips;
    }
    int Player::getMaxChips()
    {
        return MaxChips;
    }
    void Player::setMaxStepsCounter(int inputsteps)
    {
        MaxStepsCounter = inputsteps;
    }
    int Player::getMaxStepsCounter()
    {
        return MaxStepsCounter;
    }
    void Player::setMaxScore(int inputscore)
    {
        MaxScore = inputscore;
    }
    int Player::getMaxScore()
    {
        return MaxScore;
    }
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
    void Player::isLoss(Player& player, Player& dealer, bool Double)
    {
        if (player.score > 21)
            cout << "Игрок перебрал карты, дилер победил" << endl;
        else if (dealer.score > 21)
        {
            cout << "Дилер перебрал карты, игрок победил" << endl;
            if(Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.score > dealer.score)
        {
            cout << "Счёт игрока больше, игрок победил" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 4);
            else
                player.setChips(player.getChips() + player.getInputChips() * 2);
        }
        else if (player.score < dealer.score)
        {
            cout << "Счёт дилера больше, дилер победил" << endl;
        }
        else if (player.getScore() == dealer.getScore())
        {
            cout << "Ничья!" << endl;
            if (Double)
                player.setChips(player.getChips() + player.getInputChips() * 2);
            else
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
        cout << "Ваши фишки: " << chips << endl;
    }
    void Player::addCard(Card card) {
        hand.push_back(card);
    }
    int Player::getScore() {
        score = 0;
        for (auto& elem : hand)
        {
            if (elem.getValue() == 11 && score + elem.getValue() > 21)//TODO: Подумать как можно обращаться к карте по ее номиналу
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