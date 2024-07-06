#include <array>
#include <string>

#ifndef BLACKJACK_INCLUDE_SHARED_CONSTANTS_H_
#define BLACKJACK_INCLUDE_SHARED_CONSTANTS_H_

static const std::array<std::string, 13> valid_card_values = {
    "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

static const std::array<std::string, 4> valid_card_suits = {"Clubs", "Diamonds",
                                                            "Hearts", "Spades"};

#endif // !BLACKJACK_INCLUDE_SHARED_CONSTANTS_H_
