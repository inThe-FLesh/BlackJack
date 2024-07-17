#include "agent.hpp"
#include "card.hpp"
#include "deck.hpp"

#include <memory>
#include <vector>

class Dealer : Agent {
public:
  Dealer();

private:
  std::shared_ptr<std::vector<Card>> deck_;
  std::vector<Card> hand_;
  Card hidden_card_;
};
