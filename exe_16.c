#include "Defining_types.h"

#ifdef DEBUG



void Save(char* filename)
{
	//The Save function has started

	int ItemsCount = GetItemCount();

	OskarActor_Header OskarActor_HeaderItem;
	OskarActor_HeaderItem.Version = 1;
	OskarActor_HeaderItem.ItemsCount = ItemsCount;

	//The details of the header have been filled
	FILE* file = fopen(filename, "wb");
	if (!file)
	{
		//Unable to open file
		exit(1);
	}
	//The fille opens
	fwrite(&OskarActor_HeaderItem, sizeof(OskarActor_Header), 1, file);
	//The head was written in the file
	OskarActor* curr = Head;
	while (curr->next)
	{
		fwrite(curr, sizeof(OskarActor), 1, file);
		curr = curr->next;
	}
	//The data was written in the file
	fclose(file);
	//The file is closed, the function Save is finished
}


#endif // DEBUG











