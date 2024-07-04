#include "Card.h"
    Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}
    int Card::getValue() {
        //����� �� 2 �� 10 ����� �������� ����� ���������
        if (rank <= TEN)
            return rank;
        //����� 11-13 - �������� 10
        else if (rank >= JACK && rank <= KING)
            return 10;
        //��� - ���� 1 ���� 11 � ����������� �� ����� �����
        return 11;
    }

    string Card::getRank()
    {
        if (rank == TWO)
            return "TWO";
        if (rank == THREE)
            return "THREE";
        if (rank == FOUR)
            return "FOUR";
        if (rank == FIVE)
            return "FIVE";
        if (rank == SIX)
            return "SIX";
        if (rank == SEVEN)
            return "SEVEN";
        if (rank == EIGHT)
            return "EIGHT";
        if (rank == NINE)
            return "NINE";
        if (rank == TEN)
            return "TEN";
        if (rank == JACK)
            return "JACK";
        if (rank == QUEEN)
            return "QUEEN";
        if (rank == KING)
            return "KING";
        if (rank == ACE)
            return "ACE";
    }

    string Card::getSuit()
    {
        if (suit == CLUBS)
            return "Clubs";
        if (suit == DIAMONDS)
            return "Diamonds";
        if (suit == HEARTS)
            return "Hearts";
        return "Spades";
    }
    void Card::setValue(int inputValue)
    {
        rank = inputValue;
    }
    void Card::showCard() {
        cout << getRank() << " of " << getSuit() << " (" << getValue() << ") ";
    }