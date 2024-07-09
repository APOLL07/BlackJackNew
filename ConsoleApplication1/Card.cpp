#include "Card.h"
    Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}
    int Card::getValue() {
        //карты от 2 до 10 имеют значения своих номиналов
        if (rank <= TEN)
            return rank;
        //карты 11-13 - значение 10
        else if (rank >= JACK && rank <= KING)
            return 10;
        //туз - либо 1 либо 11 в зависимости от суммы очков
        return 11;
    }

    string Card::getRank()
    {
        if (rank == TWO)
            return "Два";
        if (rank == THREE)
            return "Три";
        if (rank == FOUR)
            return "Четыре";
        if (rank == FIVE)
            return "Пять";
        if (rank == SIX)
            return "Шесть";
        if (rank == SEVEN)
            return "Семь";
        if (rank == EIGHT)
            return "Восемь";
        if (rank == NINE)
            return "Девять";
        if (rank == TEN)
            return "Десять";
        if (rank == JACK)
            return "Валет";
        if (rank == QUEEN)
            return "Королева";
        if (rank == KING)
            return "Король";
        if (rank == ACE)
            return "Туз";
    }

    string Card::getSuit()
    {
        if (suit == CLUBS)
            return "Трефы";
        if (suit == DIAMONDS)
            return "Бубны";
        if (suit == HEARTS)
            return "Черви";
        return "Пики";
    }
    void Card::setValue(int inputValue)
    {
        rank = inputValue;
    }
    void Card::showCard() {
        cout << getRank() << " " << getSuit() << "|";
    }