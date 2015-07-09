/*

    this bitch displays the logfile into the screen.

 */
#include <stdio.h>
#include "/code/include/pmc.h"

FILE *datafile;

typedef struct {
	unsigned long long File_Size;
	char File_Name[1024];
} MyZip;

MyZip MZ;

int ViewLog()
{
	int i = 0;

	datafile = fopen("/code/tape/DataBase.dat", "rb");
	if (!datafile)
	{
		printf("error at /code/tape/DataBase.dat!\n");
		exit (1);
		return 1;
	}

	while (!feof(datafile))
	{
		i++;
		fread(&MZ, sizeof(MyZip), 1, datafile);
		if (feof(datafile))
			break;

		printf("user-record number: %i of database\n", i);
		printf("%s", MZ.File_Name);
		printf("%llu\n", MZ.File_Size);
	}
	printf("************************************\n");

	fclose(datafile);

	return 0;
}

int main()
{
	ViewLog();

	return 0;
}