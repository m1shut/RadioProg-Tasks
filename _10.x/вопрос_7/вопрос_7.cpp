#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;
using deck_type = array<Card, 52>;
using index_type = deck_type::size_type;

const int maxResult = 21;
const int minResult = 17;

enum Rank {
	rank_2,
	rank_3,
	rank_4,
	rank_5,
	rank_6,
	rank_7,
	rank_8,
	rank_9,
	rank_10,
	rank_jack,
	rank_queen,
	rank_king,
	rank_ace,

	max_rang
};

enum Suit {
	suit_club,
	suit_diamonds,
	suit_heart,
	suit_spade,

	max_suit
};

struct Card {
	Rank rank;
	Suit suit;

};

struct Player {
	int score;
};


void printCard(const Card& card) {
	switch (card.rank) {
	case Rank::rank_2: cout << "2"; break;
	case Rank::rank_3: cout << "3"; break;
	case Rank::rank_4: cout << "4"; break;
	case Rank::rank_5: cout << "5"; break;
	case Rank::rank_6: cout << "6"; break;
	case Rank::rank_7: cout << "7"; break;
	case Rank::rank_8: cout << "8"; break;
	case Rank::rank_9: cout << "9"; break;
	case Rank::rank_10: cout << "10"; break;
	case Rank::rank_jack: cout << "J"; break;
	case Rank::rank_queen: cout << "Q"; break;
	case Rank::rank_king: cout << "K"; break;
	case Rank::rank_ace: cout << "A"; break;
	default:
		cout << "Error";
		break;
	}

	switch (card.suit) {
	case Suit::suit_club: cout << "C"; break;
	case Suit::suit_diamonds: cout << "D"; break;
	case Suit::suit_heart: cout << "H"; break;
	case Suit::suit_spade: cout << "S"; break;
	default:
		cout << "Error";
		break;
	}
}


deck_type createDeck() {
	deck_type deck;

	index_type card = 0;
	auto suits = static_cast<int> (Suit::max_suit);
	auto ranks = static_cast<int> (Rank::max_rang);

	for (int i = 0; i < suits; ++i) {
		for (int j = 0; j < ranks; ++j) {
			deck[card].suit = static_cast<Suit>(i);
			deck[card].rank = static_cast<Rank>(j);
			++card;
		}
	}

	return deck;
}

void printDeck(const deck_type& deck) {
	for (const auto& card : deck) {
		printCard(card);
		cout << "\t" << "\n";
	}
}

void shuffleDeck(deck_type& deck) {
	static mt19937 mt{ static_cast<mt19937::result_type>(std::time(nullptr)) };
	shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card) {
	if (card.rank <= Rank::rank_10) {
		return (static_cast<int>(card.rank) + 2);
	}

	switch (card.rank) {
	case Rank::rank_jack:
	case Rank::rank_queen:
	case Rank::rank_king:
		return 10;
	case Rank::rank_ace:
		return 11;

	default:
		return 0;
	}
}

bool playerHit() {
	while (true) {
		cout << "\nPress(h) to hit and press (s) to stand ";
		char symbol;
		cin >> symbol;
		if (symbol == 'h')
			return true;
		else if (symbol == 's')
			return false;

	}
}

bool playerTurn(const deck_type& deck, Player& player, index_type& nextCardValue) {
	while (true) {
		if (player.score > maxResult) {
			cout << "You lose!";
			return true;
		}
		else {
			if (playerHit()) {
				int cardValue = getCardValue(deck[nextCardValue++]);
				player.score += cardValue;
				cout << "You took a " << cardValue << " and youre score is: " << player.score;
			}
			else {
				return false;
			}
		}
	}
}

bool dealerTurn(const deck_type& deck, Player& dealer, index_type& nextCardValue) {
	while (dealer.score < minResult) {
		int cardValue = getCardValue(deck[nextCardValue++]);
		dealer.score += cardValue;
		cout << "\nThe diler took a " << cardValue << " and dealer has: " << dealer.score;
	}

	if (dealer.score > maxResult) {
		cout << "Dealer lose";
		return true;
	}
	return false;
}

bool playBlackjack(const deck_type& deck) {
	index_type nextCardIndex = 0;

	Player dealer{ getCardValue(deck[nextCardIndex++]) };
	cout << "The dealer is showing: " << dealer.score;

	Player player{ getCardValue(deck[nextCardIndex++]) };
	player.score += 2;
	cout << "\nYou score: " << player.score;

	if (playerTurn(deck, player, nextCardIndex)) {
		return false;
	}
	if (dealerTurn(deck, dealer, nextCardIndex)) {
		return true;
	}

	return (player.score > dealer.score);
}

int main() {
	auto deck = createDeck();

	shuffleDeck(deck);

	if (playBlackjack(deck)) {
		cout << "\nYou win!!!";
	}
	else if (!playBlackjack(deck))
		cout << "\nYou lose:(";

	return 0;
}

