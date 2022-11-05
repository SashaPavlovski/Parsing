#include "Defining_types.h"



void Load(char* fileName) {

	//The Load function has started

	writeToFile = fopen(fileName, "rb");
	if (!writeToFile) {
		//Unable to open file
		exit(1);
	}
	//The fille opens

	OskarActor_Header oskarActorHeaderTyphus;
	if (!(fread(&oskarActorHeaderTyphus, sizeof(OskarActor_Header), 1, writeToFile)))
	{
		//Could not read the file
		exit(1);
	}
	fclose(writeToFile);
	OskarActor* rowOfData = (OskarActor*)malloc(sizeof(OskarActor)*oskarActorHeaderTyphus.ItemsCount);
	fread(rowOfData, sizeof(OskarActor), 1, writeToFile);

		//free(rowOfData);



}
