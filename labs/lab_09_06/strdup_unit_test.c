#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strdup(const char *s)
{
  int len = strlen (s) + 1;
  void *new = malloc (len);

  if (new == NULL)
    return NULL;

  return (char *)memcpy(new, s, len);	
}



void test_strdup(void)
{
	int err_count = 0;


	char str[11] = "0123456789";
	char *copy;
	char *icopy;

	copy = my_strdup(str);
	icopy = strdup(str);

	if (strcmp(copy,icopy) != 0)
	{
		err_count++;
		printf("%s\n", copy);
		printf("%s\n", icopy);
	}


	char str2[11] = "asdfghjklz";
	char *copy2;
	char *icopy2;

	copy2 = my_strdup(str2);
	icopy2 = strdup(str2);

	if (strcmp(copy2,icopy2) != 0)
	{
		err_count++;
		printf("%s\n", copy2);
		printf("%s\n", icopy2);
	}

	char str3[11] = "";
	char *copy3;
	char *icopy3;

	copy3 = my_strdup(str3);
	icopy3 = strdup(str3);

	if (strcmp(copy3,icopy3) != 0)
	{
		err_count++;
		printf("%s\n", copy2);
		printf("%s\n", icopy2);
	}
    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}


int main(void)
{
	test_strdup();
	return 0;
}