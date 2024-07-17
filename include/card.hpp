#include <string>

#ifndef BLACKJACK_INCLUDE_CARD_H_
#define BLACKJACK_INCLUDE_CARD_H_

class Card {
private:
  int value_ = 0;
  std::string name_;
  std::string suit_;
  bool Is_Ace = false;

  void SetValue();

public:
  Card(std::string name, std::string suit);

  int GetValue();

  std::string GetSuit();

  void SwapAceVal();
};

#endif // BLACKJACK_INCLUDE_CARD_H_
