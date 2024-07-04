
#include "Game.h"

int main()
{
    setlocale(LC_ALL, "Ru");
    bool flag = true;
    bool flag2 = true;
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
        cout << "0 - Выйти" << endl;
        cin >> choise;
        switch (choise)
        {
        case'1':
            cout << "Сделайте ставку" << endl;
            cin >> stavka;
            player.setInputChips(stavka);
            while (player.getInputChips() > player.getChips() || player.getInputChips() % 5 != 0)
            {
                if (player.getInputChips() > player.getChips())
                    cout << "У Вас на балансе недостаточно фишек" << endl;
                else if (player.getInputChips() % 5 != 0)
                    cout << "Ваша ставка должна быть кратна 5" << endl;
                cout << "Сделайте ставку" << endl;
                cin >> stavka;
                player.setInputChips(stavka);
            }
            cout << "Ставка принята!" << endl;
            player.setChips(player.getChips() - player.getInputChips());
            player.clearHand();
            dealer.clearHand();
            flag2 = true;
            player.setStepsCounter(0);
            Game::startGame(player, dealer, deck);
            while (flag2)
            {
                if (player.getScore() == 21 && player.getStepsCounter() == 2)
                {
                    cout << "У игрока блэкджэк!" << endl;
                    player.setChips(player.getChips() + player.getInputChips() * 3);
                    flag2 = false;
                    break;
                }
                else if (dealer.getScore() == 21 && player.getStepsCounter() == 2)
                {
                    cout << "У дилера блэкджэк!" << endl;
                    flag2 = false;
                    break;
                }
                cout << "Хотите взять карту?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                cin >> choise;
                switch (choise)
                {
                case'1':
                    player.addCard(deck.getRandomCard());
                    Game::showScore(player, "p");
                    if (player.getScore() > 21)
                    {
                        cout << "Вы перебрали карты, дилер победил" << endl;
                        flag2 = false;
                    }
                    break;
                case'2':
                    Game::showScore(dealer, "d");
                    while (dealer.getScore() < 17)
                    {
                        dealer.addCard(deck.getRandomCard());
                        Game::showScore(dealer, "d");
                    }
                    Player::isLoss(player, dealer);
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
        case'0':
            cout << "До Свидания!" << endl;
            flag = false;
            break;
        default:
            cout << "Введите возможный вариант" << endl;
            break;
        }
    }
}
