#include "deck.hpp"
#include <memory>
#include <vector>

class Agent {
public:
  virtual std::vector<Card> GetHand() { return hand_; }

  virtual void UpdateHand(std::vector<Card> new_cards) {
    for (Card card : new_cards) {
      hand_.push_back(card);
    }
  }

  virtual void ClearHand() { hand_.clear(); }

private:
  std::shared_ptr<Deck> deck_;
  std::vector<Card> hand_;
};
