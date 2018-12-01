#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//void readline()



void print_string(int word_count, char *data)
{
	for (int i = 0; i < word_count; i++)
	{
		printf("%c ", data[i]);
	}
}

int main(void)
{

	int start = 0, stop = 5;
	char set_buff[5];
	char *string = malloc(10* sizeof(char));
	int k = 0;
	//char string1[5];
	//char string2[5];
	//char *str;
	//str = string;
	printf("input ur string: \n");

	fgets(set_buff,6,stdin);
	//printf("%c", set_buff[4]);
	for (int i = 0; i < 5; i++)
	{
		string[i] = set_buff[i];
	}

	fgets(set_buff,6,stdin);
	for (int i = 5; i < 10; i++)
	{

		string[i] = set_buff[k];
		k++;
	}


	for (int i = 0; i < 10; i++)
	{
		printf("%c", string[i]);
	}





	

/*


	fgets(string1,6,stdin);
	//fgets(string2,6,stdin);


	for (int i = 0; i < 6; i++)
	{
		printf("%c ", string1[i]);
	}

	printf("\n");
	fgets(string1,6,stdin);
	for (int i = 0; i < 6; i++)
	{
		printf("%c ", string1[i]);
	}
*/

}