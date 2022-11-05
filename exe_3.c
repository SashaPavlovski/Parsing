#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)


int main_3()
{
	printf("please enter our last name and Name and between them is a space\n");
	char strUserLN[100];
	gets(strUserLN);
	char* token = strtok(strUserLN, " ");
	printf("%s\n", token);
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			printf("%s ", token);
		}

	}
	return 0;
}