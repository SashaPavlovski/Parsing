#include "Defining_types.h"

#ifdef DEBUG

void UpdatePopolarity(int inedx)
{
	//The UpdatePopolarity function has started
	OskarActor* move = Head;

	if (!move)
	{
		//There are no entries
		exit(1);
	}
	while (move != NULL)
	{
		//the Index that entered is Index

		if (move->Index == inedx)
		{
			//A match was found
			move->Popolarity = move->Popolarity + 1;
			//The PrintAllMoviesForYear function has finished
			exit(0);
		}

		move = move->next;
	}

	//The function UpdatePopolarity finished and did not find a same index
}

#endif // DEBUG
