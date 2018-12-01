#include <stdio.h>
#include <string.h>



int my_strspn(const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++) 
	{

		for (j = 0; s[j]; j++) 
		{
			if (s[j] == p[i])
				break;
		}
		if (!s[j])
			break;
	}
	return (i);	
}

void test_strspn(void)
{
	int err_count = 0;



	char str[11] = "0123456789";
 	char sym[11] = "210";

 	if (my_strspn(str,sym) != strspn(str,sym))
 	{
 		printf("%s\n", str);
 		printf("%s\n", sym);
 		printf("Result 1: %d\n", my_strspn(str,sym));
 		err_count++;
 	}


 	char str2[11] = "0314256789";
 	char sym2[11] = "210";
 	if (my_strspn(str2,sym2) != strspn(str2,sym2))
 	{
 		printf("%s\n", str2);
 		printf("%s\n", sym2);
 		printf("Result 2: %d\n", my_strspn(str2,sym2));
 		err_count++;
 	}



 	char str3[11] = "0314256789";
 	char sym3[11] = "aaaa1a2a0a";
 	if (my_strspn(str3,sym3) != strspn(str3,sym3))
 	{
 		printf("%s\n", str3);
 		printf("%s\n", sym3);
 		printf("Result 3: %d\n", my_strspn(str3,sym3));
 		err_count++;
 	}



 	char str4[15] = "aaaa4256789";
 	char sym4[11] = "2a10";
  	if (my_strspn(str4,sym4) != strspn(str4,sym4))
 	{
 		printf("%s\n", str4);
 		printf("%s\n", sym4);
 		printf("Result 4: %d\n", my_strspn(str4,sym4));
 		err_count++;
 	}



 	char str5[11] = "3401256789";
 	char sym5[11] = "210";
  	if (my_strspn(str5,sym5) != strspn(str5,sym5))
 	{
 		printf("%s\n", str5);
 		printf("%s\n", sym5);
 		printf("Result 5: %d\n", my_strspn(str5,sym5));
 		err_count++;
 	}

 	char str6[11] = "1111111111";
 	char sym6[11] = "1111111111";
  	if (my_strspn(str6,sym6) != strspn(str6,sym6))
 	{
 		printf("%s\n", str6);
 		printf("%s\n", sym6);
 		printf("Result 6: %d\n", my_strspn(str6,sym6));
 		err_count++;
 	}

 	char str7[11] = "3401256789";
 	char sym7[11] = "";
  	if (my_strspn(str7,sym7) != strspn(str7,sym7))
 	{
 		printf("%s\n", str7);
 		printf("%s\n", sym7);
 		printf("Result 7: %d\n", my_strspn(str7,sym7));
 		err_count++;
 	}


  	char str8[11] = "";
 	char sym8[11] = "210";
  	if (my_strspn(str8,sym8) != strspn(str8,sym8))
 	{
 		printf("%s\n", str8);
 		printf("%s\n", sym8);
 		printf("Result 8: %d\n", my_strspn(str8,sym8));
 		err_count++;
 	}


 	char str9[11] = "";
 	char sym9[11] = "";
  	if (my_strspn(str9,sym9) != strspn(str9,sym9))
 	{
 		printf("%s\n", str9);
 		printf("%s\n", sym9);
 		printf("Result 9: %d\n", my_strspn(str9,sym9));
 		err_count++;
 	}

  	char str10[11] = "aaaaaaa";
 	char sym10[11] = "bbbbbbb";
  	if (my_strspn(str10,sym10) != strspn(str10,sym10))
 	{
 		printf("%s\n", str10);
 		printf("%s\n", sym10);
 		printf("Result 10: %d\n", my_strspn(str10,sym10));
 		err_count++;
 	}
    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}




int main(void)
{
	test_strspn();
	return 0;
}
















     // char str[11] = "0123456789";
 // 	char sym[11] = "210";
 // 	printf("%s\n", str);
 // 	printf("%s\n", sym);
 // 	printf("Result 1: %d\n", my_strspn(str,sym));



 	// printf("\n");
 	// char str2[11] = "210";
 	// char sym2[11] = "0123456789";
 	// printf("%s\n", str2);
 	// printf("%s\n", sym2);
 	// printf("Result 2: %d\n", my_strspn(str2,sym2));



 	// printf("\n");
 	// char str3[11] = "210";
 	// char sym3[11] = "0314256789";
 	// printf("%s\n", str3);
 	// printf("%s\n", sym3);
 	// printf("Result 3: %d\n", my_strspn(str3,sym3));



 // 	printf("\n");
 // 	char str4[11] = "0314256789";
 // 	char sym4[11] = "210";
 // 	printf("%s\n", str4);
 // 	printf("%s\n", sym4);
 // 	printf("Result 4: %d\n", my_strspn(str4,sym4));



	// printf("\n");
 // 	char str5[11] = "0314256789";
 // 	char sym5[11] = "aaaa1a2a0a";
 // 	printf("%s\n", str5);
 // 	printf("%s\n", sym5);
 // 	printf("Result 5: %d\n", my_strspn(str5,sym5));

	// printf("\n");
 // 	char str6[15] = "aaaa4256789";
 // 	char sym6[11] = "2a10";
 // 	printf("%s\n", str6);
 // 	printf("%s\n", sym6);
 // 	printf("Result 6: %d\n", my_strspn(str6,sym6));


 // 	char str7[11] = "3401256789";
 // 	char sym7[11] = "210";
 // 	printf("%s\n", str7);
 // 	printf("%s\n", sym7);
 // 	printf("Result 7: %d\n", my_strspn(str7,sym7));
