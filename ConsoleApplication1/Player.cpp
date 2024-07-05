#include "Player.h"
#include "Game.h"
bool Player::CheckOnSplit(Player &player)
{
    for (int i = 0; i < Lefthand.size() - 1;i++)
    {
        return Lefthand[i].getRank() == Lefthand[i + 1].getRank();
    }
}
void Player::Split(Player& player, Player& dealer, Deck& deck)
{
    bool Split = false;
    for (int i = 0; i < Lefthand.size() - 1; i++)
    {
        if (Lefthand[i].getRank() == Lefthand[i + 1].getRank())
            Split = true;
    }
    if (Split)
    {
        if (player.getChips() - player.getInputChips() > 0)
        {
            bool flag = true;
            bool leftHandDouble = false;
            bool rightHandDouble = false;
            char choice = '0';
            player.setChips(player.getChips() - player.getInputChips());
            player.RightHand.push_back(Lefthand[1]);
            player.setRightStepsCounter(1);
            player.Lefthand.erase(player.Lefthand.begin() + 1, player.Lefthand.end());
            player.setLeftStepsCounter(1);
            player.addLeftCards(deck.getRandomCard());
            player.setLeftStepsCounter(player.getLeftStepsCounter() + 1);
            player.addRightCards(deck.getRandomCard());
            player.setRightStepsCounter(player.getRightStepsCounter() + 1);
            Game::showLeftScore(player);
            Game::showRightScore(player);
            while (flag) { // lefthand
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
                    player.addLeftCards(deck.getRandomCard());
                    player.setLeftStepsCounter(player.getLeftStepsCounter() + 1);
                    Game::showLeftScore(player);
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
                    else
                    {
                        leftHandDouble = true;
                        Game::DoubleLeft(player, dealer, deck, leftHandDouble);
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
            while (flag) {//right hand
                flag = true;
                if(player.getRightStepsCounter() == 2)
                Game::showRightScore(player);
                cout << "Хотите добрать карту в правую руку?" << endl;
                cout << "1 - Да" << endl;
                if (player.getRightStepsCounter() == 2)
                    cout << "2 - Дабл(правая рука)" << endl;
                cout << "0 - Нет" << endl;
                cin >> choice;
                switch (choice)
                {
                case '1':
                    player.addRightCards(deck.getRandomCard());
                    player.setRightStepsCounter(player.getRightStepsCounter() + 1);
                    cout << "Правая рука:" << endl;
                    Game::showRightScore(player);
                    if (player.getRightHandScore() > 21)
                    {
                        cout << "Вы перебрали карты в правой руке" << endl;
                        flag = false;
                    }
                    else if (player.getRightHandScore() == 21)
                    {
                        flag = false;
                        break;
                    }
                    break;
                case '2':
                    if (player.getRightStepsCounter() > 2)
                        cout << "Введите допустимый вариант" << endl;
                    else
                    {
                        rightHandDouble = true;
                        Game::DoubleRight(player, dealer, deck, rightHandDouble);
                        flag = false;
                        break;
                    }
                    break;
                case'0':
                    Game::showScore(dealer, "d");
                    while (dealer.getLeftHandScore() < 17)
                    {
                        dealer.addLeftCards(deck.getRandomCard());
                        Game::showScore(dealer, "d");
                    }
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
}
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
    void Player::clearHands()
    {
        Lefthand.clear();
        RightHand.clear();
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
            if (elem.getValue() == 11 && score + elem.getValue() > 21)//TODO: Подумать как можно обращаться к карте по ее номиналу
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
            if (elem.getValue() == 11 && score + elem.getValue() > 21)//TODO: Подумать как можно обращаться к карте по ее номиналу
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