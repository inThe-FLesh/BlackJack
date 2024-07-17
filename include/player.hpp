#include "agent.hpp"
#include "deck.hpp"
#include <memory>

#ifndef BLACKJACK_INCLUDE_PLAYER_H_
#define BLACKJACK_INCLUDE_PLAYER_H_

class Player : public Agent {
public:
  Player(Deck deck, int initial_chips);

  // use negative argument to reduce chip count
  void UpdateChips(int chips); 

private:
  int id_;
  bool hand_in_progress = false;
  std::shared_ptr<Deck> deck_;
  std::vector<Card> hand_;
  unsigned long chips_;
};

#endif // BLACKJACK_INCLUDE_PLAYER_H_

