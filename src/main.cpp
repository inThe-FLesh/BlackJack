#include "main.hpp"
#include "player.hpp"
#include <memory>
#include <vector>

int main() {
  Deck deck(10);
  std::vector<Card> deck_of_cards = deck.GetDeck();

  for (Card card : deck_of_cards) {
    std::cout << "value: " << card.GetValue() << " suit: " << card.GetSuit()
              << std::endl;
  }
}
