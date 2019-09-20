#pragma once
#include "MessageServiceController.h"

//Class that interacts with user and calls the controller with the input
class MessageServiceInterface {
public:
    MessageServiceInterface(MessageServiceController &iMsgController) : msgServiceController{iMsgController} { }
    bool ProcessInput(); // returns true when finished
    void terminate();

    //some constants
    const string ONE = "1";
    const string TWO = "2";
    const string THREE = "3";
    const string FOUR = "4";
    const string FIVE = "5";
private:
    MessageServiceController msgServiceController;
};
