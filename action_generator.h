#include <stdio.h>
#include "ir_array.h"
#include "pos_core.h"

struct Action {
    // action to core
};

class ActionGenerator { 
public:
    ActionGenerator();
    // generate action based on IR array touch info
    // and current status of POS core
    Action getAction(const CoreStatus& core_status);

private:
    // pointer to ir array used
    // nullptr indicates lack of ir array
    IRArray *ir_array_ptr;
};