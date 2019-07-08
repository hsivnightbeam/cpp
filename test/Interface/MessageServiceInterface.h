#pragma once
#include "MessageServiceController.h"

//Class that interacts with user and calls the controller with the input
class MessageServiceInterface {
public:
    MessageServiceInterface(MessageServiceController &iMsgController) : msgServiceController{iMsgController} { }
    bool ProcessInput(); // returns true when finished
    void terminate();
private:
    MessageServiceController msgServiceController;
};
