#include "card.hpp"
#include "shared_constants.hpp"

#include <iostream>
#include <random>
#include <vector>

#ifndef BLACKJACK_INCLUDE_DECK_H_
#define BLACKJACK_INCLUDE_DECK_H_

class Deck {
private:
  int size_ = 0;
  bool deck_initialised_ = false;
  std::vector<Card> deck_;

  Card GenRandomCard();

public:
  Deck(int size);

  std::vector<Card> GetDeck();
};

#endif // BLACKJACK_INCLUDE_DECK_H_
