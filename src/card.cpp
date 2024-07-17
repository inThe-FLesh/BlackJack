#include "card.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

Card::Card(std::string name, std::string suit) {
  name_ = name;
  suit_ = suit;
  SetValue();
}

void Card::SetValue() {
  if (name_ == "A") {
    value_ = 11;
    Is_Ace = true;
    return;
  }

  if (name_ == "J" || name_ == "Q" || name_ == "K") {
    value_ = 10;
    return;
  }

  try {
    value_ = std::stoi(name_);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

int Card::GetValue() { return value_; }

std::string Card::GetSuit() { return suit_; }

void Card::SwapAceVal() {
  if (Is_Ace) {
    value_ = 1;
  }
}
