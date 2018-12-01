#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void space(char *text)
{
	int len;
	int k = 0;

	len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		if ((text[i-k] == ' ' && text[i-k+1] == ' '))
		{
			for (int j = i - k; j < len; j++)
			{
				text[j] = text[j+1];
			}
			k++;
		}

		if ((text[i-k-1] == '\n' && text[i-k] == ' ' && text[i-k+1] != ' '))
		{
			for (int j = i - k; j < len; j++)
			{
				text[j] = text[j+1];
			}
			k++;
		}
	}

	if (text[0] == ' ' && text[1] != ' ') //удаление оставшегося пробела в начале 
	{
		for (int p = 0; p < len; p++) 
		{
			text[p] = text[p+1];
		}
	}

	int r = strlen(text);
	//printf("zxcv%c\n", text[r-1]);
	if (text[r-1] == ' ')
		text[r-1] = '\0';
}




void test_space(void)
{
	int err_count = 0;

	char str1[10] = "   aa   a";
	char res1[10] = "aa a";
	space(str1);

	if (strcmp(str1,res1) != 0)
	{
		err_count++;
		printf("1\n");
	}



	char str2[10] = "  aa  a  ";
	char res2[10] = "aa a";
	space(str2);

	if (strcmp(str2,res2) != 0)
	{
		//int r = strlen(str2);
		//printf("sdf:%c\n", str2[r]);
		//printf("%s\n", );
		err_count++;
		printf("2\n");
	}


	char str3[10] = "a a a";
	char res3[10] = "a a a";
	space(str3);

	if (strcmp(str3,res3) != 0)
	{
		//int r = strlen(str3);
		//printf("sdf:%c\n", str3[r]);
		//printf("%s\n", );
		err_count++;
		printf("3\n");
	}

	char str4[10] = "";
	char res4[10] = "";
	space(str4);

	if (strcmp(str4,res4) != 0)
	{
		//int r = strlen(str3);
		//printf("sdf:%c\n", str3[r]);
		//printf("%s\n", );
		err_count++;
		printf("4\n");
	}

	
    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}



int main(void)
{
	test_space();
	return 0;
}
