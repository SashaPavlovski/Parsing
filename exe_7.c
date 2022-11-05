
#ifdef DEBUG



int GetItemCount()
{
	//The GetItemCount function has started
	OskarActor* move = Head;
	int countItems = 0;
	if (!move)
	{
		//There are no entries
		exit(1);
	}
	while (move != NULL)
	{
		countItems++;
		move = move->next;
	}
	//The amount of items is
	//The funPrint function has finished
	return countItems;
}

#endif // DEBUG
















