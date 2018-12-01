#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char read;
	int count = 0;
	char *rpa;
	char *rpb;
	char buffer[200];
	char copy[30];
	int change_count = 0;
	//char *rp_str;
	//char delimetr;

	char c;

	if (argc != 4)
	{
		fprintf(stderr, "Not enough arguments\n");
	}
	else
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			fprintf(stderr, "Could not open file\n");	
		}
		else
		{
			if (fscanf(fp, "%c", &c) != 1)
			{
				printf("Empty file!!!\n");
			}
			else
			{
				//delimetr = *argv[4];
				rewind(fp);
				rpa = argv[2];
				rpb = argv[3];
				printf("Lines before changing.\n");
				while ((read = getdelim(&line, &len, 'S', fp)) != -1)
				{
					printf("%s\n", line);
					printf("------------------------------\n");
					count += read;
				}
				rewind(fp);

				count = 0;
				len = 0;
				printf("Lines after changing.\n");
				while ((read = getdelim(&line, &len, 'S', fp)) != -1)
				{
					int l_len = strlen(line);
					for (int i = 0; i < l_len; i++)
						copy[i] = line[i];
					replace(line, rpa, rpb, buffer);
					//printf("line: %s\n", line);
					//printf("copy: %s\n", copy);
					if (strcmp(copy, line) != 0)
						change_count++;
					printf("%s\n", line);
					printf("------------------------------\n");
					count += read;
				}

				if (change_count == 0)
					printf("No changes in file!!!\n");

			}
		}
	}

	free(line);
	fclose(fp);
	
	return 0;
}