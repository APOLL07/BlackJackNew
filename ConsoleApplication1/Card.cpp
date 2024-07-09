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
            return "���";
        if (rank == THREE)
            return "���";
        if (rank == FOUR)
            return "������";
        if (rank == FIVE)
            return "����";
        if (rank == SIX)
            return "�����";
        if (rank == SEVEN)
            return "����";
        if (rank == EIGHT)
            return "������";
        if (rank == NINE)
            return "������";
        if (rank == TEN)
            return "������";
        if (rank == JACK)
            return "�����";
        if (rank == QUEEN)
            return "��������";
        if (rank == KING)
            return "������";
        if (rank == ACE)
            return "���";
    }

    string Card::getSuit()
    {
        if (suit == CLUBS)
            return "�����";
        if (suit == DIAMONDS)
            return "�����";
        if (suit == HEARTS)
            return "�����";
        return "����";
    }
    void Card::setValue(int inputValue)
    {
        rank = inputValue;
    }
    void Card::showCard() {
        cout << getRank() << " " << getSuit() << "|";
    }