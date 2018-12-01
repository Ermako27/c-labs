#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SWAP(a, b, size)                                                      \
      do                                                                              \
        {                                                                              \
          size_t __size = (size);                                                      \
          char *__a = (a), *__b = (b);                                              \
          do                                                                      \
            {                                                                      \
              char __tmp = *__a;                                                      \
              *__a++ = *__b;                                                      \
              *__b++ = __tmp;                                                      \
            } while (--__size > 0);                                                      \
        } while (0)

void sort(int size, int m, char *data[m])
{
	char *tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strcmp(data[j], data[j+1]) > 0)
			{
				printf("%s %s\n",data[j], data[j+1]);
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
}


int main(void)
{
	int k= 0, p =0;
	char s1[] = "redf ermakov";
	char **s2 = calloc(2, sizeof(char*));
	int cmp;
	char *tmp;
	for (int i = 0; i < 2; i++)
	{
		s2[i] = malloc(5*sizeof(char));
	}

	int len = strlen(s1);


	for (int i = 0; i < len; i++)
	{
		if (s1[i] != ' ')
		{
			s2[k][p] = s1[i];
			p++;
		}
		else
		{
			k++;
			p = 0;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", s2[i]);
	}

	printf("111\n");

	/*

	if (s2[0] < s2[1])
		printf("i works\n");
*/

//	cmp = strncmp(s2[0], s2[1],3);
//	printf("%d\n", cmp);

/*
	tmp = s2[0];
	s2[0] = s2[1];
	s2[1] = tmp;
*/
	
	sort(2,20,s2);

	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", s2[i]);
	}

	


}
