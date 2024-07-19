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

  virtual std::shared_ptr<Deck> GetDeck() { return deck_; }

  virtual void UpdateHand() {
    if (deck_ == nullptr)
      throw std::runtime_error("Deck is not initialised");

    hand_.push_back(deck_->GetNextCard());
  }

  void SetHand() {
    if (deck_ == nullptr)
      throw std::runtime_error("deck is empty, cannot draw a card");

    for (uint8_t i = 0; i < 1; i++) {

      hand_.push_back(deck_->GetNextCard());
    }
  }

  void UpdateDeck(std::shared_ptr<Deck> deck) { deck_ = deck; }

protected:
	std::shared_ptr<Deck> deck_;
  std::vector<Card> hand_;
};

#endif // !BLACKJACK_INCLUDE_AGENT_H_
