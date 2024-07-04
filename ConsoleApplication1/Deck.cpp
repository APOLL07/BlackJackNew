#include "Deck.h"
    int Deck::FillRandomNumber(int Start, int End)
    {
        random_device rd;
        mt19937 rand(rd());
        uniform_int_distribution<> dist(Start, End);
        return dist(rand);
    }
    Deck::Deck() {
        for (int j = Card::CLUBS; j <= Card::SPADES; j++)
            for (int i = Card::TWO; i <= Card::ACE; i++)
            {
                deck.push_back(Card((Card::Rank)i, (Card::Suit)j));
            }
    }
    Card Deck::getRandomCard() {
        Card card((Card::Rank)FillRandomNumber(Card::TWO, Card::ACE), (Card::Suit)FillRandomNumber(Card::CLUBS, Card::SPADES));
        return card;
    }