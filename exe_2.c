#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)


int main_2()
{

	printf("please enter our Name and last name and between them is a space\n");
	char strUserNL[100];
	gets(strUserNL);

	char* token = strtok(strUserNL, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}





  return 0;
}

