#include "agent.hpp"
#include "deck.hpp"
#include <memory>

#ifndef BLACKJACK_INCLUDE_PLAYER_H_
#define BLACKJACK_INCLUDE_PLAYER_H_

class Player : public Agent {
public:
	Player(std::vector<Card> deck, int initial_chips);

  // use negative argument to reduce chip count
  void UpdateChips(int chips);

private:
  int id_;
  bool hand_in_progress = false; 
  unsigned long chips_;
};

#endif // BLACKJACK_INCLUDE_PLAYER_H_

