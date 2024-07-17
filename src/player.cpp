#include "player.hpp"
#include <memory>

Player::Player(Deck deck, int initial_chips) {
  deck_ = std::make_shared<Deck>(deck);
  chips_ = initial_chips;
}

void Player::UpdateChips(int chips) { chips_ += chips; }

