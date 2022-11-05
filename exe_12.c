#include "Defining_types.h"
#include <time.h>


#ifdef DEBUG

void Run()
{
	//The Run function has started
	time_t t = time(NULL);
	srand(t);
	int num;
	for (int i = 0; i < 100000; i++)
	{
		num = rand();
		UpdatePopolarity(num);
	}

	//The function Run finished
}

#endif // DEBUG








