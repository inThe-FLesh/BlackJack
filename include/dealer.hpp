#include "agent.hpp"
#include "card.hpp"
#include "deck.hpp"

#include <memory>
#include <vector>

class Dealer : Agent {
public:
  Dealer();

  std::vector<Card> GetHand();

  void UpdateHand(std::vector<Card> new_cards);

  void ClearHand();

private:
  std::shared_ptr<Deck> deck_;
  std::vector<Card> hand_;
  Card hidden_card_;
};
