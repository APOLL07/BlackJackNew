
#include "Game.h"
#include <fstream>
int main()
{
    setlocale(LC_ALL, "Ru");
    string S = "PlayerStatistic.txt";
    ofstream out;
    ifstream in;
    bool flag = true;
    bool flag2 = true;
    bool flag3 = true;
    bool Double = false;
    int choise = 0;
    int stavka;
    Player player;
    Player dealer;
    Deck deck;
    cout << "Добро пожаловать в БлэкДжэк!" << endl;
    player.ReadStatistics(S);
    while (flag)
    {
        if (player.getChips() == 0)
        {
            cout << "Похоже, Вы всё проиграли( загляните в Ваш баланс, возможно, есть варианты отыграться?" << endl;
        }
        cout << "Выберите действие" << endl;
        cout << "1 - Начать игру" << endl;
        cout << "2 - Посмотреть баланс" << endl;
        cout << "3 - Посмотреть статистику" << endl;
        cout << "0 - Выйти" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Сделайте ставку" << endl;
            cout << "Текущие фишки:" << player.getChips() << endl;
            cout <<  "0 - Отменить ставку" << endl;
            cin >> stavka;
            if (stavka == 0)
                break;
            player.setInputChips(stavka);
            while (player.getInputChips() > player.getChips() || player.getInputChips() % 5 != 0 || player.getInputChips() == 0)
            {
                if (player.getInputChips() > player.getChips())
                    cout << "У Вас на балансе недостаточно фишек" << endl;
                else if (player.getInputChips() % 5 != 0)
                    cout << "Ваша ставка должна быть кратна 5" << endl;
                cout << "Сделайте ставку" << endl;
                cout << "Текущие фишки:" << player.getChips() << endl;
                cout << "0 - Отменить ставку" << endl;
                cin >> stavka;
                if (stavka == 0)
                    break;
                player.setInputChips(stavka);
            }
            cout << "Ставка принята!" << endl;
            player.setChips(player.getChips() - player.getInputChips());
            player.clearHands();
            dealer.clearHands();
            flag2 = true;
            Double = false;
            player.setLeftStepsCounter(0);
            player.setRightStepsCounter(0);
            Game::startGame(player, dealer, deck);
            while (flag2)
            {
                if (Game::CheckBlackJack(player, dealer))
                {
                    flag2 = false;
                    break;
                }
                cout << "Хотите взять карту?" << endl;
                cout << "1 - Да" << endl;
                if (player.getLeftStepsCounter() == 2)
                    cout << "2 - Дабл" << endl;
                if (player.getLeftStepsCounter() == 2 && player.CheckOnSplit(player))
                    cout << "3 - Сплит" << endl;
                cout << "0 - Нет" << endl;
                cin >> choise;
                switch (choise)
                {
                case 1:
                    Game::AddCardForPlayer(player, deck, "left");
                    Game::showScore(player, "p");
                    if (player.getLeftHandScore() > 21)
                    {
                        Game::showScore(dealer, "d");
                        cout << "Вы перебрали карты, дилер победил" << endl;
                        flag2 = false;
                    }
                    else if (player.getLeftHandScore() == 21)
                    {
                        Game::showScore(dealer, "d");
                        Game::DealerAddCards(player, dealer, deck);
                        Game::isLoss(player, dealer, Double);
                        flag2 = false;
                        break;
                    }
                    break;
                case 2:
                    if (player.getLeftStepsCounter() > 2)
                        cout << "Введите допустимый вариант" << endl;
                    else if (Game::CheckBet(player))
                    {
                        Double = true;
                        Game::Double(player, dealer, deck);
                        Game::isLoss(player, dealer, Double);
                        flag2 = false;
                        break;
                    }
                    break;
                case 3:
                    if (player.getLeftStepsCounter() != 2 && !player.CheckOnSplit(player))
                        cout << "Введите допустимый вариант" << endl;
                    else if (Game::CheckBet(player))
                    {
                        player.Split(player, dealer, deck);
                        flag2 = false;
                        break;
                    }
                     break;
                case 0:
                    Game::showScore(dealer, "d");
                    Game::DealerAddCards(player, dealer, deck);
                    Game::isLoss(player, dealer, Double);
                    flag2 = false;
                    break;
                default:
                    cout << "Введите допустимый вариант" << endl;
                    break;
                }
            }
            if (player.getLeftStepsCounter() > player.getMaxLeftStepsCounter())
                player.setMaxLeftStepsCounter(player.getLeftStepsCounter());
            if (player.getRightStepsCounter() > player.getMaxRightStepsCounter())
                player.setMaxRightStepsCounter(player.getMaxLeftStepsCounter());
            if (player.getMaxLeftStepsCounter() + player.getMaxRightStepsCounter() > player.getMaxSumStepsCounter())
                player.setMaxSumStepsCounter(player.getMaxLeftStepsCounter() + player.getMaxRightStepsCounter());
            if (player.getChips() > player.getMaxChips())
                player.setMaxChips(player.getChips());   
            player.writeStatistics(S); 
            break;
        case 2:
            player.showChips();
            if (player.getChips() < 20)
                flag3 = true;
            if (player.getChips() < 10)
            {
                while (flag3)
                {
                    cout << "Желаете пополнить баланс?" << endl;
                    cout << "1 - Да" << endl;
                    cout << "0 - Нет" << endl;
                    cin >> choise;
                    switch (choise)
                    {
                    case 1:
                            cout << "Ваш баланс пополнен, приятной игры!" << endl;
                            player.setChips(20);
                            player.writeStatistics(S);
                            flag3 = false;                        
                        break;
                    case 0:
                        cout << "Приятной игры!" << endl;
                        flag3 = false;
                        break;
                    default:
                        cout << "Введите возможный вариант" << endl;
                        break;
                    }
                }
            }
            break;
        case 3:
            player.ReadStatistics(S);
            Game::ShowStatistic(player);
            break;
        case 0:
            cout << "До Свидания!" << endl;
            flag = false;
            break;
        default:
            cout << "Введите возможный вариант" << endl;
            break;
        }
    }
    system("pause");
}
