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

  virtual void UpdateHand() {
		std::vector<Card> deck = deck_->GetDeck();
    if (deck.empty())
			throw std::runtime_error("deck is empty, cannot draw a card");

    hand_.push_back(deck.back());
    deck.pop_back();
  }

  virtual void SetHand() {
    for (uint8_t i = 0; i < 1; i++) {
			if(deck_ == NULL)
				throw std::runtime_error("deck is empty, cannot draw a card");
	
      hand_.push_back(deck_->GetDeck().back());
      deck_->GetDeck().pop_back();
    }
  }

  virtual void UpdateDeck(std::shared_ptr<Deck> deck) { deck_ = deck; }

private:
  std::shared_ptr<Deck> deck_;
  std::vector<Card> hand_;
};

#endif // !BLACKJACK_INCLUDE_AGENT_H_
