#include <dd.h>
#include <ddlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/code/include/pmc.h" /* this is pmc header dir :) */

FILE *pmcdszfile;

struct dif *d;
dszlog dsz; /* from pmc.h */

char buf[300];
char temp_username[25];
char templine[80];
char filename[80];
char Cpsrate[80];
char filesize[80];

/*  fread(&rock,sizeof(struct DayDream_NodeInfo),1,node_info);
 */

/* main bitch whore shit */
int main(int argv, char *argc[])
{
	if (argv == 1)
	{
		printf("need to run from DayDream\n");
		exit(1);
	}

	d = dd_initdoor(argc[1]);

	sprintf(buf, "%s/doors/pmcdsz.dat", getenv("DAYDREAM"));

	pmcdszfile = fopen(buf, "ab");
	if (!pmcdszfile)
	{
		dd_sendstring(d, "error at pmcdsz.dat, inform sysop!\n");
		dd_close(d);
		exit(1);
	}

	dd_close(d);
	return 0;
}
