#include "player.hpp"
#include <memory>

Player::Player(std::vector<Card> deck, int initial_chips) {
  deck_ = std::make_shared<std::vector<Card>>(deck);
  chips_ = initial_chips;
}
void Player::UpdateChips(int chips) { chips_ += chips; };
