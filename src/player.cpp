#include "player.hpp"
#include <memory>

Player::Player(std::shared_ptr<Deck> deck, int initial_chips) {
  deck_ = deck;
  chips_ = initial_chips;
}
void Player::UpdateChips(int chips) { chips_ += chips; };
