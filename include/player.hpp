#include "agent.hpp"
#include "deck.hpp"
#include <memory>
#include <mutex>
#include <thread>

class Player : Agent {
public:
  Player(std::shared_ptr<Deck> deck, int initial_chips);

private:
  void UpdateChips();

private:
  int id_;
  std::thread update_thread_;
  std::mutex chips_mutex_;
  std::atomic<int> chip_differnce_;
  bool hand_in_progress = false;
  std::shared_ptr<Deck> deck_;
  std::vector<Card> hand_;
  unsigned long chips_;
};
