
#include "MessageServiceController.h"
#include "MessageServiceInterface.h"


int UserStore::id = 0;
int MessageStore::id = 0;

int main(int, const char* [])
{

	// Create controller
    MessageServiceController msgServiceController;

    // Create interface
	MessageServiceInterface msgServiceInterface(msgServiceController);

	while (msgServiceInterface.ProcessInput() == false){

	}

	//msgServiceInterface.terminate();

	return 0;
}
