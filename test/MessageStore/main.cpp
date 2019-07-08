
#include "MessageStore.h"
#include "UserStore.h"

int UserStore::id = 0;

int main(int, const char* [])
{

	MessageStore store;



	while (store.ProcessInput() == false){

	}

	store.terminate();

	return 0;
}
