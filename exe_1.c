#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)


int main_1()
{
	char str[100] = "123,456,789,1,2,3,4,5,6,7,2000";
	char* token = strtok(str,",");
	int sum = atoi(token);
	while (token != NULL)
	{
		token = strtok(NULL, ",");
		if (token != NULL)
		{
			int numSum = atoi(token);
			sum += numSum;
		}
	
	}

	printf("%d", sum);


	return 0;
}
