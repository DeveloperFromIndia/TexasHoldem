#pragma once
#include <iostream>
#include <string>
#include <time.h>

using namespace std;


// Карта	
struct Card
{
	string seniority; // Старшинство
	string suit;      // Масть

	void SetCard(string seniority, string suit)
	{
		this->seniority = seniority;
		this->suit = suit;
	}
};

// Рука
class Hand
{
	string name;
	Card * card;
	float balance;
public:
	// Конструкторы
	Hand()
	{
		card = nullptr;
		name = "X";
		balance = 0;
	}
	// Конструктор с параметрами
	Hand(Card *card, string name, float balance)
	{
		this->card = card;
		this->name = name;
		this->balance = balance;
	}


	// Диструкторы
	~Hand()
	{
		card = nullptr;
		name = "X";
		balance = 0;
	}

	// Гетеры
	float getBalance()
	{
		return balance;
	}
	string getName()
	{
		return name;
	}
	Card * getCards()
	{
		return card;
	}

	// Сетеры
	void setBalance(float balance)
	{
		this->balance = balance;
	}
	void setName(string name)
	{
		this->name = name;
	}
	
	
	int setCard(Card card,int n)
	{
		if (n > 2)
			return 0;

		// Если места не выделенно - выделяем
		if (this->card == nullptr)
			this->card = new Card[1];

		if (n == 1 || n == 0)
			this->card[0] = card;

		if (n == 2 || n == 1)
			this->card[1] = card;
		
		return 0;
	}

};

// Колода 
class Deck
{
private:
	Card * deck;		// Колода
	int amount_card;	// Кол-во карт
public:
	Deck() {
		amount_card = 52;

		// Выдача масти
		for (int i = 0, counter = 0; i < 4; i++)
		{
			// Создание карт
			Card A, K, Q, J;
			Card Ten;
			Card Nine;
			Card Eight;
			Card Seven;
			Card Six;
			Card Five;
			Card Four;
			Card Three;
			Card Two;

			// Выдаю масть карте
			switch (i)
			{
			case 0:	// Чирва
				A.suit = "C";
				K.suit = "C";
				Q.suit = "C";
				J.suit = "C";
				Ten.suit = "C";
				Nine.suit = "C";
				Eight.suit = "C";
				Seven.suit = "C";
				Six.suit = "C";
				Five.suit = "C";
				Four.suit = "C";
				Three.suit = "C";
				Two.suit = "C";
				break;
			case 1: // Бубна
				A.suit = "B";
				K.suit = "B";
				Q.suit = "B";
				J.suit = "B";
				Ten.suit = "B";
				Nine.suit = "B";
				Eight.suit = "B";
				Seven.suit = "B";
				Six.suit = "B";
				Five.suit = "B";
				Four.suit = "B";
				Three.suit = "B";
				Two.suit = "B";
				break;
			case 2: // Креста
				A.suit = "K";
				K.suit = "K";
				Q.suit = "K";
				J.suit = "K";
				Ten.suit = "K";
				Nine.suit = "K";
				Eight.suit = "K";
				Seven.suit = "K";
				Six.suit = "K";
				Five.suit = "K";
				Four.suit = "K";
				Three.suit = "K";
				Two.suit = "К";
				break;
			case 3: // Пика
				A.suit = "П";
				K.suit = "П";
				Q.suit = "П";
				J.suit = "П";
				Ten.suit = "П";
				Nine.suit = "П";
				Eight.suit = "П";
				Seven.suit = "П";
				Six.suit = "П";
				Five.suit = "П";
				Four.suit = "П";
				Three.suit = "П";
				Two.suit = "П";
			}

			// Выдача старшинства
			A.seniority = "A";
			K.seniority = "K";
			Q.seniority = "Q";
			J.seniority = "J";
			Ten.seniority = "10";
			Nine.seniority = "9";
			Eight.seniority = "8";
			Seven.seniority = "7";
			Six.seniority = "6";
			Five.seniority = "5";
			Four.seniority = "4";
			Three.seniority = "3";
			Two.seniority = "2";
		}
	}

	~Deck()
		{
			delete[] deck;
		}

	


	void CardsToHand(Hand hand)
	{
		srand(time(NULL));
		for (int i = 0; i < 2; i++)
		{
			int x = rand() % amount_card + 1;
			hand.setCard(deck[x], i);

			// Сделать список !
			Card * tmp = new Card[amount_card - 1];
			for (int j = 0; j < amount_card - 1; j++)
				if (j != x)
					tmp[i] = deck[i];

			delete[] deck;
			deck = tmp;
			delete[] tmp;
		}
	}
	


};

// Стол
class Table
{
	Deck deck;
	Hand *players;
	int amount_players;
public:
	Table()
	{
		
	}





};