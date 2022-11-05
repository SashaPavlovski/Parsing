#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)
typedef struct s_OskarActor
{
	int Index;
	int Year;
	char Age;
	char Movie[1000];
	char Name[1000];
	int Popolarity;
	struct s_OskarActor* next;
	struct s_OskarActor* prev;
} OskarActor;


FILE* oskarFile;
FILE* writeToFile;
#define FILE_NAME "oscar_age_female.txt"

typedef struct s_OskarActor_Header
{
	int Version;
	int ItemsCount;
	char Reserved[1000];

}OskarActor_Header;



char* poi;



