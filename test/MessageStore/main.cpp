
#include "MessageStore.h"
#include "Users.h"

int main(int, const char* [])
{

	MessageStore store;

	

	while (store.ProcessInput() == false){

	}

	store.terminate();

	return 0;
}
