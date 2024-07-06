#include "player.hpp"
#include <memory>
#include <mutex>
#include <vector>

Player::Player(std::shared_ptr<Deck> deck, int initial_chips) {
  deck_ = deck;
  chip_differnce_.store(initial_chips);
  update_thread_ = std::thread(&Player::UpdateChips, this);
}

void Player::UpdateChips() {
  while (!hand_in_progress) {
    std::lock_guard<std::mutex> lock(chips_mutex_);

    if (chips_ > chip_differnce_) {
      chips_ -= chip_differnce_;
    } else {
      chips_ = 0;
    }
  }
}
