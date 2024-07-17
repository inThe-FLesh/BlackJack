#include "agent.hpp"
#include "player.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

TEST(PlayerDeckTest, InitDeck) {
	Deck deck(10);

	Player player1(deck.GetDeck(), 100);

	player1.SetHand();

	std::vector<Card> hand = player1.GetHand();

	for (int i = 0; i < hand.size(); i++) {
		EXPECT_FALSE(hand.back().GetSuit().empty());
		EXPECT_FALSE(hand.back().GetValue() != 0);
        hand.pop_back();
	}
}

TEST(PlayerDeckTest, UpdateDeckTest) {
	Deck deck1(10);

	Deck deck2(20);

	Player player1(deck1.GetDeck(), 100);

	player1.SetHand();

	EXPECT_EQ(player1.GetDeck().size(), 10);

	player1.UpdateDeck(deck2.GetDeck());

	EXPECT_EQ(player1.GetDeck().size(), 20);
}
