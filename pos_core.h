#include <stdio.h>
#include "action_generator.h"
#include "card_reader.h"

enum CoreStatus
{
    // status of POS core
    PinIn, SignatureIn, Success, Idle
};

class POSCore { 
public:
    POSCore();
    // display current status on LCD
    void displayOnLCD();
    // get current status of POS
    void getStatus();
    // switch to a certain status
    void toState(CoreStatus status);
    // go to PinIn state and get password for
    // the card read. If the password is correct,
    // go to SignatureIn status. Otherwise, display
    // the error message and go to Idle state
    void verifyCard();
    // allow user to draw signature until OK
    // is pressed, and go to Success state
    void takeSignature();
    // display a success message and reset
    // card reader for security after 5 seconds,
    // go to Idle state
    void displaySuccess();

private:
    // current status of POS core
    CoreStatus core_status_;
    // info of display device
    DisplayConfig display_config_;
    // pointer to action generator for getting user actions
    ActionGenerator *action_generator_;
    // pointer to card reader for getting card info
    CardReader *card_reader_;
};