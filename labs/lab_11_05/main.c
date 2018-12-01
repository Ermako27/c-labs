#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "functions.h"


void test_my_snprintf()
{
	int err_count = 0;


// тепличный тест 16 число

	printf("\n----------------TEST 1---------------------\n");
	printf("\nТепличный тест, вводится 16-ое число.\n\n");

	char buf1_1[100];
	char buf1_2[100]; 
    long long int a1 = 0xd;

    if  (my_snprintf(buf1_1,20, "%llx", a1) != snprintf(buf1_2,20,"%llx", a1))
    {
    	printf("1\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf1_1);
    printf("snprinf: %s\n", buf1_2);
    printf("-------------------------------------------\n\n");


// тепличный тест строка

    printf("\n----------------TEST 2---------------------\n");

    printf("\nТепличный тест, вводится строка.\n\n");

    char buf2_1[100];
	char buf2_2[100];

	char s1[3] = "abc";
    if  (my_snprintf(buf2_1,20, "%s", s1) != snprintf(buf2_2,20,"%s", s1))
    {
    	printf("2\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf2_1);
    printf("snprinf: %s\n", buf2_2);
    printf("-------------------------------------------\n\n");



// тест с двумя ключами в строке и другими символами  
    printf("\n----------------TEST 3---------------------\n");

    printf("\nТест с двумя ключами в строке и другими символами.\n\n");

    char buf3_1[100];
	char buf3_2[100];

	long long int a2 = 13;
	char s2[5] = "poka";
    if  (my_snprintf(buf3_1,20, "privet %llx %s!",a2, s2) != snprintf(buf3_2,20, "privet %llx %s!",a2, s2))
    {
    	printf("3\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf3_1);
    printf("snprinf: %s\n", buf3_2);
    printf("-------------------------------------------\n\n");



// n меньше вводимой строки 

    printf("\n----------------TEST 4---------------------\n");

    printf("\nРазмер строки больше чем n.\n\n");
    char buf4_1[100];
	char buf4_2[100];

	long long int a3 = 0xffff;
	char s3[5] = "poka";
    if  (my_snprintf(buf4_1,10, "privet %llx %s!",a3, s3) != snprintf(buf4_2,10, "privet %llx %s!",a3, s3))
    {
    	printf("4\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf4_1);
    printf("snprinf: %s\n", buf4_2);
    printf("-------------------------------------------\n\n");


// Вводится максимальное допустимое значени типа long long int 

    printf("\n----------------TEST 5---------------------\n");

    printf("\nВводится масимально допустимое значение типа long long int.\n\n");

    char buf5_1[100];
	char buf5_2[100];

	long long int a4 = 9223372036854775807;
    if  (my_snprintf(buf5_1,50, "biggest num: %llx!",a4) != snprintf(buf5_2,50, "biggest num: %llx!",a4))
    {
    	printf("5\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf5_1);
    printf("snprinf: %s\n", buf5_2);
    printf("-------------------------------------------\n\n");

// Вводится отрицательное число

    printf("\n----------------TEST 6---------------------\n");

    printf("\nВводится отрицательное число.\n\n");

    char buf6_1[100];
	char buf6_2[100];

	long long int a6 = -0xaaafff;
    if  (my_snprintf(buf6_1,50, "smallest num: %llx!",a6) != snprintf(buf6_2,50, "smallest num: %llx!",a6))
    {
    	printf("6\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf6_1);
    printf("snprinf: %s\n", buf6_2);
    printf("-------------------------------------------\n\n");


// Вводится символ
    printf("\n----------------TEST 7---------------------\n");

    printf("\nВводится символ.\n\n");

    char buf7_1[100];
	char buf7_2[100];

	long long int a7 = 'p';
	char chr = 'p';
    if  (my_snprintf(buf7_1,50, "hex of '%c' is %llx!",chr, a7) != snprintf(buf7_2,50, "hex of '%c' is %llx!",chr, a7))
    {
    	printf("7\n");
    	err_count++;
    }
    printf("my_snprintf: %s\n", buf7_1);
    printf("snprinf: %s\n", buf7_2);
    printf("-------------------------------------------\n\n");



    printf("-------------------RESULT------------------\n");
    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}


int main(void)
{
	test_my_snprintf();
	return 0;
}













// #define OK 0
// #define INCORRECT 1


// void test_filt()
// {
// 	int err_count = 0;
// 	FILE *f;

// // вещественная размерность 

// 	f = fopen("test1.txt", "r");
// 	if (filtr(f) != INCORRECT)
// 	{
// 		printf("1\n");
// 		err_count++;
// 	}
// 	fclose(f);

// // отрицательная размерность

// 	f = fopen("test2.txt", "r");
// 	if (filtr(f) != INCORRECT)
// 	{
// 		printf("2\n");
// 		err_count++;
// 	}
// 	fclose(f);

// // размерность не соответствует размеру матрицы
// 	f = fopen("test3.txt","r");
// 	if (filtr(f) != INCORRECT)
// 	{
// 		printf("3\n");
// 		err_count++;
// 	}
// 	fclose(f);

// // буква в матрице

// 	f = fopen("test4.txt","r");
// 	if (filtr(f) != INCORRECT)
// 	{
// 		printf("4\n");
// 		err_count++;
// 	}
// 	fclose(f);

// // буква в размерности

// 	f = fopen("test5.txt","r");
// 	if (filtr(f) != INCORRECT)
// 	{
// 		printf("5\n");
// 		err_count++;
// 	}
// 	fclose(f);

// // нулевая размерность 

// 	f = fopen("test6.txt","r");
// 	if (filtr(f) != INCORRECT)
// 	{
// 		printf("6\n");
// 		err_count++;
// 	}
// 	fclose(f);

// 	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
// }

// int main(void)
// {
// 	test_filt();
// 	return 0;
// }












	// printf("format_len: %d\n", format_len);

	// for (int i = 0; i < format_len; i++)
	// {
	// 	if(format[i] == '%' && format[i+1] == 's')
	// 	{
	// 		string = va_arg(argptr, char*); // взяли строку
	// 		string_len = strlen(string); // длина строки
	// 		printf("string_len: %d\n", string_len);
	// 		for (int j = 0;  j < string_len; j++) // записываем слово
	// 		{
	// 			printf("in i: %d\n", i);
	// 			printf("string[j]: %c\n", string[j]);
	// 			if (strchr(chars,string[j]) != NULL)
	// 			{
	// 				printf("tmp 2: %c\n", ptr[i+j]);
	// 				ptr[i+j] = string[j];
	// 			}
	// 			else
	// 				secret_count++;
	// 			//printf("tmp 2: %c\n", ptr[i+j]);
	// 		}
	// 		i += 1;
	// 		printf("in i: %d\n", i);
	// 		k = strlen(ptr) - secret_count;
	// 		printf("k: %d\n", k);
	// 		printf("after tmp:%s\n", ptr);
	// 	}

	// 	else
	// 	{
	// 		printf("-----------------------\n");
	// 		printf("i: %d\n", i);
	// 		printf("l: %d\n",string_len );
	// 		printf("%c\n", format[i]);
	// 		ptr[k++] = format[i];
	// 		//printf("tmp 1: %c \n", tmp[i+string_len]);
	// 	}
	// 	//k++;
	// }

	// printf("result tmp: %s\n", ptr);

	// va_end(argptr);

	// return 0;


















	// int len = strlen(format);
	// int count = 0;
	// int s = 0,l = 0;
	// va_list argptr;
	// va_start(argptr, format);
	// char *str;
	// char num_str[30];
	// long long int num; 
	// int str_len;
	// // buf[n-1] = '\0';
	// // printf("%s\n", format);
	// for (int i = 0; i < len; i++)
	// {
	// 	if (i == n)
	// 		return count;
	// 	// printf("%c\n", format[i]);
	// 	// printf("%c\n", format[i+1]);
	// 	// printf("%d\n", n);
	// 	// printf("!!!!\n");
	// 	// if (buf[i] == '\0')
	// 	// 	return 0;
	// 	if (format[i] == '%' && format[i+1] == 's')
	// 	{
	// 		printf("i: %d\n", i);
	// 		printf("%c\n", format[i]);
	// 		printf("%c\n", format[i+1]);
	// 		str = va_arg(argptr,char*);
	// 		printf("str: %s\n", str);
	// 		str_len = strlen(str);
	// 		printf("str_len: %d\n", str_len);
	// 		for (int j = 0; j < str_len; j++)
	// 		{
	// 			if (i+j == n-1)
	// 			{
	// 				break;
	// 			}
	// 			else
	// 			{
	// 				buf[i+j] = str[j];
	// 				printf("buf: %c\n", buf[i+j]);
	// 			}
	// 			s += 1;
	// 		}
	// 		i+=s;
	// 		s = 0;
	// 	}
	// 	// printf("i: %d\n", i);

	// 	if (format[i] == '%' && format[i+1] == 'l')
	// 	{
	// 		//printf("!!!!!!!!!!!!\n");
	// 		num = va_arg(argptr, long long int);
	// 		//printf("n: %llx\n", num);
	// 		itoa(num, num_str, 16);
	// 		//printf("num_str: %s\n", num_str);
	// 		str_len = strlen(num_str);
	// 		//printf("%d\n", str_len);
	// 		//printf("i: %d\n", i);
	// 		for (int j = 0; j < str_len; j++)
	// 		{
	// 			if (i+j == n-1)
	// 			{
	// 		//		printf("1111\n");
	// 				break;
	// 			}
	// 			else
	// 			{
	// 				buf[i+j] = num_str[j];
	// 		//		printf("buf: %c\n", buf[i+j]);
	// 			}
	// 			l += 1;
	// 		}
	// 		i+=l;
	// 		l = 0;
	// 	}
	// 	else 
	// 		buf[i] = format[i];

	// 	count = i;

	// }
	// va_end(argptr);
	// return count;