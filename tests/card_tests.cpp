#include "card.hpp"
#include "shared_constants.hpp"
#include <array>
#include <gtest/gtest.h>
#include <queue>

class CardTest : public testing::Test {
protected:
  CardTest() {
    for (int i = 0; i < static_cast<int>(valid_card_values.size()); i++) {
      Card card(valid_card_values.at(i), valid_card_suits.at(0));
      card_queue_.push(card);
    }
  }

  std::queue<Card> card_queue_;
};

TEST_F(CardTest, ValueTest) {
  std::array<int, 13> test_values = {11, 2, 3,  4,  5,  6, 7,
                                     8,  9, 10, 10, 10, 10};

  for (int i = 0; i < static_cast<int>(test_values.size()); i++) {
    Card current_card = card_queue_.front();
    card_queue_.pop();
    EXPECT_EQ(test_values.at(i), current_card.GetValue());
  }
}

TEST_F(CardTest, AceTest) {
  Card card("A", valid_card_suits.at(0));
  card.SwapAceVal();

  EXPECT_EQ(card.GetValue(), 1);
}
