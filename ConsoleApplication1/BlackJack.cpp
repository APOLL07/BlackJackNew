﻿
#include "Game.h"

int main()
{
    setlocale(LC_ALL, "Ru");
    bool flag = true;
    bool flag2 = true;
    bool Double = false;
    char choise = '0';
    int stavka;
    Player player;
    Player dealer;
    Deck deck;
    cout << "Добро пожаловать в БлэкДжэк!" << endl;
    while (flag)
    {
        cout << "Выберите действие" << endl;
        cout << "1 - Начать игру" << endl;
        cout << "2 - Посмотреть баланс" << endl;
        cout << "3 - Посмотреть статистику" << endl;
        cout << "0 - Выйти" << endl;
        cin >> choise;
        switch (choise)
        {
        case'1':
            if (player.getChips() == 0)
            {
                cout << "Ваш баланс был пополнен на 20 фишек, приятной игры!" << endl;
                player.setChips(20);
            }
            cout << "Сделайте ставку" << endl;
            cin >> stavka;
            player.setInputChips(stavka);
            while (player.getInputChips() > player.getChips() || player.getInputChips() % 5 != 0 || player.getInputChips() == 0)
            {
                if (player.getInputChips() > player.getChips())
                    cout << "У Вас на балансе недостаточно фишек" << endl;
                else if (player.getInputChips() % 5 != 0)
                    cout << "Ваша ставка должна быть кратна 5" << endl;
                else if (player.getInputChips() == 0)
                    cout << "Ставка не может равняться 0 фишек" << endl;
                cout << "Сделайте ставку" << endl;
                cin >> stavka;
                player.setInputChips(stavka);
            }
            cout << "Ставка принята!" << endl;
            player.setChips(player.getChips() - player.getInputChips());
            player.clearHand();
            dealer.clearHand();
            flag2 = true;
            Double = false;
            player.setStepsCounter(0);
            Game::startGame(player, dealer, deck);
            while (flag2)
            {
                if (player.getScore() == 21 && player.getStepsCounter() == 2)
                {
                    Game::showScore(dealer, "d");
                    cout << "У игрока блэкджэк!" << endl;
                    player.setChips(player.getChips() + player.getInputChips() * 3);
                    player.setVictorysByBlackJack(player.getVictorysByBlackJack() + 1);
                    flag2 = false;
                    break;
                }
                else if (dealer.getScore() == 21 && player.getStepsCounter() == 2)
                {
                    cout << "У дилера блэкджэк!" << endl;
                    player.setLoosesByBlackJack(player.getLoosesByBlackJack() + 1);
                    flag2 = false;
                    break;
                }
                cout << "Хотите взять карту?" << endl;
                cout << "1 - Да" << endl;
                if (player.getStepsCounter() == 2)
                    cout << "2 - Дабл" << endl;
                cout << "0 - Нет" << endl;
                cin >> choise;
                switch (choise)
                {
                case'1':
                    player.addCard(deck.getRandomCard());
                    player.setStepsCounter(player.getStepsCounter() + 1);
                    Game::showScore(player, "p");
                    if (player.getScore() > 21)
                    {
                        cout << "Вы перебрали карты, дилер победил" << endl;
                        flag2 = false;
                    }
                    break;
                case'2':
                    if (player.getStepsCounter() != 2)
                        cout << "Введите допустимый вариант" << endl;
                    else
                    {
                        Game::Double(player, dealer, deck, Double);
                        flag2 = false;
                        break;
                    }
                case'0':
                    Game::showScore(dealer, "d");
                    while (dealer.getScore() < 17)
                    {
                        dealer.addCard(deck.getRandomCard());
                        Game::showScore(dealer, "d");
                    }
                    Player::isLoss(player, dealer, Double);
                    flag2 = false;
                    break;
                default:
                    cout << "Введите допустимый вариант" << endl;
                    break;
                }
            }
            break;
        case'2':
            player.showChips();
            break;
        case'3':
            Game::ShowStatistic(player);
            break;
        case'0':
            cout << "До Свидания!" << endl;
            flag = false;
            break;
        default:
            cout << "Введите возможный вариант" << endl;
            break;
        }
        if (player.getStepsCounter() > player.getMaxStepsCounter())
            player.setMaxStepsCounter(player.getStepsCounter());
        if (player.getScore() > player.getMaxScore())
            player.setMaxScore(player.getScore());
        if (player.getChips() > player.getMaxChips())
            player.setMaxChips(player.getChips());
        player.setNumberOfGames(player.getNumberOfGames() + 1);
    }
}
