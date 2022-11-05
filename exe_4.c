#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include "Defining_types.h"
#pragma warning(disable:4996)

int main_4()
{
	FILE* f = fopen("oscar_age_female.txt", "r");
	if (!f)
	{
		exit(1);
	}

	char oneLine[1000];
	fgets(oneLine, sizeof(char) * 1000, f);
	while (fgets(oneLine, sizeof(char) * 1000, f))
	{
		char* index = strtok(oneLine, ",");
		char* Year = strtok(NULL, ",");
		char* Age = strtok(NULL, ",");
		poi = strtok(NULL, "\"");
		char* Name = strtok(NULL, "\"");
		poi = strtok(NULL, "\"");
		char* Movie = strtok(NULL, "\"");
		printf("the Oskar Goes to %s at %s Movie %s\n", Name, Year, Movie);
	}

	fclose(f);



	return 0;

}

