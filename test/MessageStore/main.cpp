
#include "MessageStore.h"
#include "Users.h"

int Users::id = 0;

int main(int, const char* [])
{

	MessageStore store;



	while (store.ProcessInput() == false){

	}

	store.terminate();

	return 0;
}
