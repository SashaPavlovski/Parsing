#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>
#include "Defining_types.h"
#pragma warning(disable:4996)
#define FILE_NAME "oscar_age_female.txt"

OskarActor* Head = NULL;
OskarActor* Tail = NULL;

void Add(int index,int year,char age,char movie[], char name[])
{
	//The Add function has started
	OskarActor* move = (OskarActor*)malloc(sizeof(OskarActor));
	move->Index = index;
	move->Year = year;
	move->Age = age;
	strcpy(move->Movie, movie);
	strcpy(move->Name, name);
	move->Popolarity = 0;

	move->next = NULL;
	if (!move)
	{
		//No space in memory
		exit(1);
    }
	if (Head == NULL)
	{
		//The first file is created
		Head = move;
		Tail = move;
		move->prev = NULL;
	}
	else
	{
		//A new file has been created
		move->prev = Tail;
		Tail->next = move;
		Tail = move;
	}

	//The Add function has finished
}


void funPrint()
{
	//The funPrint function has started
	OskarActor* move = Head;
	if (!move)
	{
		//There are no entries
		exit(1);
	}
	while (move != NULL)
	{
		printf("The Index is %d\nThe Year is %d\nThe Age is %d\nThe Movie is %s\nThe Name is %s\n\n\n", move->Index, move->Year, move->Age, move->Movie, move->Name);
		move = move->next;
	}
	//The funPrint function has finished
}



void LoadFile()
{
	//The LoadFile function has started

	oskarFile = fopen("oscar_age_female.txt", "r");
	if (!oskarFile)
	{
		//File not opened

		exit(1);
	}
	//The document opens

	char movieStr[1000];
	char nameStr[1000];
	char oneLine[1000];

	fgets(oneLine, 1000, oskarFile);
	//One line was read
	while (fgets(oneLine, 1000, oskarFile))
	{
		//One line was read
		int index = atoi(strtok(oneLine, ","));
		int year = atoi(strtok(NULL, ","));
		char age = (char)atoi(strtok(NULL, ","));
		poi = strtok(NULL,"\"");
		char* name = strtok(NULL, "\"");
		poi = strtok(NULL,"\"");
		char* movie = strtok(NULL, "\"");


		sprintf(movieStr, "%s", movie);
		sprintf(nameStr, "%s", name);
		

		Add(index, year, age, movieStr, nameStr);
		

	}

	funPrint();
	//The LoadFile function has finished
}


void PrintAllMoviesForYear(int Year)
{
	//The PrintAllMoviesForYear function has started
	OskarActor* move = Head;
	int amountOfMovies = 0;
	if (!move)
	{
		//There are no entries
		exit(1);
	}
	while (move != NULL)
	{
		//the year that entered is YEAR

		if (move->Year = Year)
		{
			++amountOfMovies;
			//A match was found
			printf("******************************************************************************************************************\n");
			printf("The Year is %d\nThe Age is %d\nThe Movie is %s\nThe Name is %s\n", move->Year, move->Age, move->Movie, move->Name);
		}
	
		move = move->next;
	}
	printf("\n\n\n");
	if (amountOfMovies < 0)
	{
		printf("******************************************************************************************************************\n");
		printf("There are no movies from this year in a list\n");
		//There are no movies from the year you gave in this list.
	}

	//The PrintAllMoviesForYear function has finished

}

void GetMovieByIndex(int Index)
{
	//The GetMovieByIndex function has started
	OskarActor* move = Head;
	int indexCount = 0;
	if (!move)
	{
		//There are no entries
		exit(1);
	}
	while (move != NULL)
	{
		//the Index that entered is Index

		if (move->Index == Index)
		{
			++indexCount;
			//A match was found
			printf("The Index is %d\nThe Year is %d\nThe Age is %d\nThe Movie is %s\nThe Name is %s\n", move->Index, move->Year, move->Age, move->Movie, move->Name);
			//The PrintAllMoviesForYear function has finished
			exit(0);
		}

		move = move->next;
	}
	if (indexCount <  0)
	{
		printf("There is no index inserted in this list\n");
		//There is no index inserted in this list
	}
	//The function finished and did not find a same index
}

void Replace(OskarActor* item)
{
	//The Replace function has started
	OskarActor* change = item;

	if (change == NULL)
	{
		//No need to swap. No Items in list
		//There are no numbers
	}
	else if (change->next == NULL)
	{
		//No need to swap. This is the only number
		//single
	}
	else if (change == Head && change->next == Tail)
	{
		//swap between two num. There are only two numbers
		change->next = NULL;
		change->prev = Tail;
		Tail->prev = NULL;
		Tail->next = change;
		Tail = change;
		Head = change->prev;
		//only two numbers
	}
	else if (change == Head)
	{
		//swap starts from the beginning. This is the first document
		change->next->prev = NULL;
		change = change->next->next;
		Head->next->next = Head;
		Head->prev = Head->next;
		Head->next = change;
		change->prev = Head;
		Head = Head->prev;
		change = Head->next;
		//Change from the beginning

	}
	else if (change->next == Tail)
	{
		//swap between two num. The number is one before last
		change->next->prev = change->prev;
		change->prev = Tail;
		Tail->next = change;
		change->next = NULL;
		Tail->prev->next = change->prev;
		Tail = Tail->next;

		//change the tail
	}
	else
	{
		//swap between two num. The change starts from the middle
		change->next->prev = change->prev;
		change->prev = change->next;
		change->next = change->next->next;
		change->prev->next = change;
		change->prev->prev->next = change->prev;
		change->next->prev = change;

		//Change from the middle
	}

	//The Replace function has finished
}

void Sorting_between_two()
{
	//enters the Sorting_between_two function

	OskarActor* curr = Head;
	if (!curr)
	{
		//The list is empty
		// The list is empty
		return;
	}

	char change = 1;
	while (change != 0)
	{
		//The sorting process has started

		change = 0;
		while (curr != NULL)
		{
			if (curr->next != NULL && curr->Age > curr->next->Age)
			{
				//the current number
				//the next number
				//The current number is bigger than the next number
				Replace(curr);
				change++;
			}
			curr = curr->next;
		}

		curr = Head;
	}

	printf("List sorted by age\n\n");
	funPrint();
	//The Sorting_between_two function has finished
}


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
	printf("The amount of items is %d\n", countItems);
	//The amount of items is
	//The funPrint function has finished
	return countItems;
}


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



void Load(char* fileName) {

	//The Load function has started

	writeToFile = fopen(fileName, "rb");
	if (!writeToFile) {
		//Unable to open file
		exit(1);
	}
	//The fille opens

	OskarActor_Header oskarActorHeaderTyphus;
	fread(&oskarActorHeaderTyphus, sizeof(OskarActor_Header),1, writeToFile);
	fclose(writeToFile);
	//char* rowOfData = (char*)malloc(sizeof(char)*1000);
	//fgets(rowOfData)

		//free(rowOfData);



}



int main()
{

	LoadFile();
	//PrintAllMoviesForYear(2008);
	//GetMovieByIndex(4);
	//Sorting_between_two();
	//GetItemCount();
	//Run();
	//Save("aaa.bin");
	Load("aaa.bin");
	return 0;
}

