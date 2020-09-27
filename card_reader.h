#include <stdio.h>
#include <string>
#include <unordered_map>

class CardReader { 
public:
    CardReader();
    // purge currently saved card info
    void reset();
    // typically after a swipe, update current card number
    void updateCardNumber();
    // return most recently read card number
    int getCardNumber();
    // given card number, return saved pin of that card
    // if the card information does not exist, return an empty string
    // assume that there is no empty pin
    std::string getPinFromCardNumber(int card_number);

private:
    // most recently read card number
    int current_card_number_;
    // dictionary where key is card number and value the corresponding pin
    std::unordered_map<int, std::string> card_pin_;
};