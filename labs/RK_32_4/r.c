#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char *a = "qwer_34";
	printf("%s\n", a);
	int len = strlen(a);
	printf("%d\n",len);
	printf("%c\n", a[len-1]);
	
	return 0;
}