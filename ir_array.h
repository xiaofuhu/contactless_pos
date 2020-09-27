#include <stdio.h>
#include <string>
#include <vector>

typedef struct DisplayConfig {
    // TODO: determine necessary config fields
} DisplayConfig;

typedef struct TouchType {
    // x coordinate of touch in millimeters
    int x_coord;
    // y coordinate of touch in millimeters
    int y_coord;
    // x size (width) of touch object in millimeters
    int x_size;
    // y size (height) of touch object in millimeters
    int y_size;
    // timestamp of touch in milliseconds
    int timestamp;
} TouchType;

typedef std::vector<TouchType> IRArrayState;

class IRArray { 
public:
    IRArray();
    IRArray(const DisplayConfig& display_config);
    // update read values of ir array and save to state
    void updateIrArray();
    // return a vector of touch location in pixels
    // empty vector indicates there is no touch
    std::vector<std::pair<int, int> > getTouchLocation();

private:
    // info of display device for configuring IR array
    DisplayConfig display_config_;
    // current state of ir array
    // a vector of detected touches on "virtual screen"
    IRArrayState ir_array_state_;
};