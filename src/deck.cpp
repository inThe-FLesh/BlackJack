#include "deck.hpp"
#include <cstdlib>
#include <stdexcept>
#include <vector>

Card Deck::GenRandomCard() {
  std::random_device device;
  std::mt19937 rng(device());
  std::uniform_int_distribution<std::mt19937::result_type> dist13(0, 12);
  std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);

  try {
    std::string card_value = valid_card_values.at(dist13(rng));
    std::string card_suit = valid_card_suits.at(dist4(rng));

    Card card(card_value, card_suit);

    if (card.GetValue() < 2)
        throw std::runtime_error("Card Value Incorrect");

    return card;
  } catch (std::out_of_range &e) {
    std::cerr << "Deck tried to select a card that was out of range: "
              << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

Deck::Deck(int size) {
  if (size < 1) {
    throw std::out_of_range("size cannot be less than 0");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < size; i++) {
    Card card = GenRandomCard();
    deck_.push_back(card);
  }

  size_ = size;
  deck_initialised_ = true;
}

std::vector<Card> Deck::GetDeck() { return deck_; }
