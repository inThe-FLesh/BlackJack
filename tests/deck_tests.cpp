#include "card.hpp"
#include "deck.hpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>

TEST(DeckTest, Size0) {
  EXPECT_THROW({ Deck deck(0); }, std::out_of_range);
}

TEST(DeckTest, HandlesNegativeSize) {
  EXPECT_THROW({ Deck deck(-10); }, std::out_of_range);
}

TEST(DeckTest, EmptyDeckTest) {
	Deck deck(1);

	deck.GetNextCard();

	EXPECT_THROW(deck.GetNextCard(), std::runtime_error);
}
