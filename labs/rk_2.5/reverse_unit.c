#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>




void reverse(char *t1,char *t2)
{
	int len;
	len = strlen(t1);

	for (int i = 0; i < len; i++)
	{
		printf("%c", t1[i]);
	}

	for (int i = 0; i < len+1; i++)
	{
		t2[i] = t1[len-i];
	}

	printf("\n");
	printf("\n");
	t2[len] = t1[0];

	//for (int i = 0; i < len+1; i++)
	//{
	//	printf("%c", t2[i]);
	//}

	//printf("\n");


}




void test_rev(void)
{
	int err_count = 0;

	char str1[10] = "";
	char res1[10] = "";
	char t1[10];

	reverse(str1,t1);

	if (strcmp(t1,res1) != 0)
	{
		err_count++;
		printf("1\n");
	}


	// char str2[10] = "qwer";
	// char res2[10] = "rewq";
	// char t2[10];

	// reverse(str2,t2);

	// if (strcmp(t2,res2) != 0)
	// {
	// 	err_count++;
	// 	printf("2\n");
	// }


	
    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}



int main(void)
{
	test_rev();
	return 0;
}
