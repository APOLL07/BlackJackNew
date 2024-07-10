#include "Player.h"
#include "Game.h"
#include <fstream>
bool Player::CheckOnSplit(Player &player)
{
        return Lefthand[0].getRank() == Lefthand[1].getRank();
}
//void Player::writeChipsStatistic(string S) const
//{
//    ofstream f(S, ios::binary);
//    f.write((const char*)&chips, sizeof(int));
//    f.close();
//}
//void Player::readChipsStatistic(string S)
//{
//    ifstream f(S, ios::binary);
//    f.read((char*)&chips, sizeof(int));
//    f.close();
//}
void Player::writeStatistics(string S) const
{
    ofstream f(S, ios::binary);
    f.write((const char*)&MaxLeftStepsCounter, sizeof(int));
    f.write((const char*)&MaxRightStepsCounter, sizeof(int));
    f.write((const char*)&MaxSumStepsCounter, sizeof(int));
    f.write((const char*)&MaxChips, sizeof(int));
    f.write((const char*)&VictorysCounter, sizeof(int));
    f.write((const char*)&LosesCounter, sizeof(int));
    f.write((const char*)&VictorysByBlackJack, sizeof(int));
    f.write((const char*)&CloseWins, sizeof(int));
    f.write((const char*)&NumberOfGames, sizeof(int));
    f.write((const char*)&DrawsCounter, sizeof(int));
    f.write((const char*)&LoosesByBlackJack, sizeof(int));
    f.write((const char*)&chips, sizeof(int));

    f.close();
}
void Player::ReadStatistics(string S)
{
    ifstream f(S, ios::binary);
    if (f.is_open())
    {
        f.read((char*)&MaxLeftStepsCounter, sizeof(int));
        f.read((char*)&MaxRightStepsCounter, sizeof(int));
        f.read((char*)&MaxSumStepsCounter, sizeof(int));
        f.read((char*)&MaxChips, sizeof(int));
        f.read((char*)&VictorysCounter, sizeof(int));
        f.read((char*)&LosesCounter, sizeof(int));
        f.read((char*)&VictorysByBlackJack, sizeof(int));
        f.read((char*)&CloseWins, sizeof(int));
        f.read((char*)&NumberOfGames, sizeof(int));
        f.read((char*)&DrawsCounter, sizeof(int));
        f.read((char*)&LoosesByBlackJack, sizeof(int));
        f.read((char*)&chips, sizeof(int));
        f.close();
    }
}
void Player::Split(Player& player, Player& dealer, Deck& deck)
{
    if (CheckOnSplit(player))
    {

            bool flag = true;
            bool leftHandDouble = false;
            bool rightHandDouble = false;
            char choice = '0';
            player.RightHand.push_back(Lefthand[1]);
            player.setRightStepsCounter(1);
            player.Lefthand.erase(player.Lefthand.begin() + 1, player.Lefthand.end());
            player.setLeftStepsCounter(1);
            Game::AddCardForPlayer(player, deck, "left");
            Game::AddCardForPlayer(player, deck, "right");
            Game::showSplitScore(player, "left");
            Game::showSplitScore(player, "right");
            Game::ShowFirstScore(dealer);
            while (flag)
            { // lefthand
                flag = true;
                cout << "Хотите добрать карту в левую руку?" << endl;
                cout << "1 - Да" << endl;
                if (player.getLeftStepsCounter() == 2)
                    cout << "2 - Дабл(левая рука)" << endl;
                cout << "0 - Нет" << endl;
                cin >> choice;
                switch (choice)
                {
                case '1':
                    Game::AddCardForPlayer(player, deck, "left");
                    Game::showSplitScore(player, "left");
                    if (player.getLeftHandScore() > 21)
                    {
                        cout << "Вы перебрали карты в левой руке" << endl;
                        flag = false;
                    }
                    else if (player.getLeftHandScore() == 21)
                    {
                        flag = false;
                        break;
                    }
                    break;
                case '2':
                    if (player.getLeftStepsCounter() > 2)
                        cout << "Введите допустимый вариант" << endl;
                    else if (Game::CheckBet(player))
                    {
                        leftHandDouble = true;
                        Game::DoubleForSplit(player, dealer, deck, "left");
                        flag = false;
                        break;
                    }
                    break;
                case'0':
                    flag = false;
                    break;
                default:
                    cout << "Введите возможный вариант" << endl;
                    break;
                }
            }
            flag = true;
            while (flag)
            {//right hand
                if (player.getRightStepsCounter() == 2)
                {
                    Game::showSplitScore(player, "right");
                    Game::ShowFirstScore(dealer);
                }
                cout << "Хотите добрать карту в правую руку?" << endl;
                cout << "1 - Да" << endl;
                if (player.getRightStepsCounter() == 2)
                    cout << "2 - Дабл(правая рука)" << endl;
                cout << "0 - Нет" << endl;
                cin >> choice;
                switch (choice)
                {
                case '1':
                    Game::AddCardForPlayer(player, deck, "right");
                    Game::showSplitScore(player, "right");
                    Game::ShowFirstScore(dealer);
                    if (player.getRightHandScore() > 21)
                    {
                        cout << "Вы перебрали карты в правой руке" << endl;
                        Game::showScore(dealer, "d");
                        flag = false;
                    }
                    else if (player.getRightHandScore() == 21)
                    {
                        Game::showScore(dealer, "d");
                        Game::DealerAddCards(player, dealer, deck);
                        flag = false;
                        break;
                    }
                    break;
                case '2':
                    if (player.getRightStepsCounter() > 2)
                        cout << "Введите допустимый вариант" << endl;
                    else if (Game::CheckBet(player))
                    {
                        leftHandDouble = true;
                        Game::DoubleForSplit(player, dealer, deck, "left");
                        flag = false;
                        break;
                    }
                    break;
                case'0':
                    Game::showScore(dealer, "d");
                    Game::DealerAddCards(player, dealer, deck);
                    flag = false;
                    break;
                default:
                    cout << "Введите возможный вариант" << endl;
                    break;
                }
            }
            Game::isLoss(player, dealer, leftHandDouble, rightHandDouble);
        }
}
    void Player::addLoses()
    {
        LosesCounter++;
    }
    int Player::getLoses()
    {
        return LosesCounter;
    }
    void Player::addVictorys()
    {
        VictorysCounter++;
    }
    int Player::getVictorys()
    {
        return VictorysCounter;
    }
    void Player::addNumberOfGames()
    {
        NumberOfGames++;
    }
    int Player::getNumberOfGames()
    {
        return NumberOfGames;
    }
    void Player::addVictorysByBlackJack()
    {
        VictorysByBlackJack++;
    }
    int  Player::getVictorysByBlackJack()
    {
        return VictorysByBlackJack;
    }
    void Player::addLoosesByBlackJack()
    {
        LoosesByBlackJack++;
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
    void Player::setMaxLeftStepsCounter(int inputsteps)
    {
        MaxLeftStepsCounter = inputsteps;
    }
    int Player::getMaxLeftStepsCounter()
    {
        return MaxLeftStepsCounter;
    }
    void Player::setMaxRightStepsCounter(int inputsteps)
    {
        MaxRightStepsCounter = inputsteps;
    }
    int Player::getMaxRightStepsCounter()
    {
        return MaxRightStepsCounter;
    }
    void Player::setMaxSumStepsCounter(int inputsteps)
    {
        MaxSumStepsCounter = inputsteps;
    }
    int Player::getMaxSumStepsCounter()
    {
        return MaxSumStepsCounter;
    }
    void Player::addCloseWins()
    {
        CloseWins++;
    }
    int Player::getCloseWins()
    {
        return CloseWins;
    }
    void Player::clearHands()
    {
        Lefthand.clear();
        RightHand.clear();
    }
    int Player::getDrawsCounter()
    {
        return DrawsCounter;
    }
    void Player::addDrawsCounter()
    {
        DrawsCounter++;
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
        Lefthand[0].showCard();
    }
    int Player::getFirstCardScore()
    {
        return Lefthand[0].getValue();
    }
    void Player::showLeftHand()
    {
        for (auto& card : Lefthand) {
            card.showCard();
        }
    }
    void Player::showRightHand()
    {
        for (auto& card : RightHand) {
            card.showCard();
        }
    }
    void Player::showChips()
    {
        cout << "Ваши фишки: " << chips << endl;
    }
    void Player::addLeftCards(Card card) {
        Lefthand.push_back(card);
    }
    void Player::addRightCards(Card card) {
        RightHand.push_back(card);
    }
    int Player::getLeftHandScore() {
        score = 0;
        for (auto& elem : Lefthand)
        {
            if (elem.getValue() == 11 && score + elem.getValue() > 21)
            {
                score += 1;
            }
            else
                score += elem.getValue();
        }
        return score;
    }
    int Player::getRightHandScore() {
        score = 0;
        for (auto& elem : RightHand)
        {
            if (elem.getValue() == 11 && score + elem.getValue() > 21)
            {
                score += 1;
            }
            else
                score += elem.getValue();
        }
        return score;
    }
    void Player::setLeftStepsCounter(int counter)
    {
        LeftStepsCounter = counter;
    }
    int Player::getLeftStepsCounter()
    {
        return LeftStepsCounter;
    }
    void Player::setRightStepsCounter(int counter)
    {
        RightStepsCounter = counter;
    }
    int Player::getRightStepsCounter()
    {
        return RightStepsCounter;
    }
    int Player::SumStepsCounter()
    {
        return LeftStepsCounter + RightStepsCounter;
    }