#include "deck.hpp"
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <vector>

#ifndef BLACKJACK_INCLUDE_AGENT_H_
#define BLACKJACK_INCLUDE_AGENT_H_

class Agent {
public:
  virtual std::vector<Card> GetHand() { return hand_; }

  std::vector<Card> GetDeck() { return *deck_; }

  virtual void UpdateHand() {
    if (deck_ == NULL)
      throw std::runtime_error("deck is empty, cannot draw a card");

    hand_.push_back(deck_->back());
    deck_->pop_back();
  }

  void SetHand() {
    for (uint8_t i = 0; i < 1; i++) {
      if (deck_ == NULL)
        throw std::runtime_error("deck is empty, cannot draw a card");

      hand_.push_back(deck_->back());
      deck_->pop_back();
    }
  }

  void UpdateDeck(std::vector<Card> deck) {
    deck_ = std::make_shared<std::vector<Card>>(deck);
  }

protected:
  std::shared_ptr<std::vector<Card>> deck_;
  std::vector<Card> hand_;
};

#endif // !BLACKJACK_INCLUDE_AGENT_H_
