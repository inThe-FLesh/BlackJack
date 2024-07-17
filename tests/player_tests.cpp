#include "agent.hpp"
#include "player.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

TEST(PlayerDeckTest, InitDeck) {
	Deck deck(10);

	std::vector<Card> new_deck = deck.GetDeck();

	std::cout << new_deck.back().GetSuit() << std::endl;

	Player player1(deck, 100);

	player1.SetHand();

	std::vector<Card> hand = player1.GetHand();

	while(!hand.empty()) {
		EXPECT_FALSE(hand.back().GetSuit().empty());
		EXPECT_FALSE(hand.back().GetValue() != 0);
	}
}
