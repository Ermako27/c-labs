#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void strreverse(char* begin, char* end) { // для itoa
	
	char aux;
	while(end>begin)
	{
		aux=*end;
		*end--=*begin; 
		*begin++=aux;
	}
	
}
	
void itoa(int value, char* str, int base) { // функция перевода в любую систему счислению по основанию base 
	
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	
	// Validate base
	if (base<2 || base>35)
	{
		*wstr='\0'; 
		return; 
	}
	// Take care of sign
	if ((sign=value) < 0) 
		value = -value;
	// Conversion. Number is reversed.
	do *wstr++ = num[value%base]; while(value/=base);
	if(sign<0) 
		*wstr++='-';
	*wstr='\0';
	// Reverse string
	strreverse(str,wstr-1);
	
}


int my_snprintf(char *buf, int n, char *format, ...)
{
	int count;

	char chars[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char signes[] = "-!@#$&?/|*.=,<>";
	va_list argptr;
	va_start(argptr, format);


	char tmp[100000]; // временная переменная хранящаяя всю строку без ограничения

	int format_len = strlen(format); // длина вводимого формата

	char *string; // указатель на строку из (...)
	int string_len = 0;

	long long int x;
	int llx_len;
	char x_str[30];

	int k = 0;
	int secret_count = 0;


	printf("format_len: %d\n", format_len);

	for (int i = 0; i < format_len; i++)
	{
		if(format[i] == '%' && format[i+1] == 's')
		{
			//string = va_arg(argptr, char*); // взяли строку
			//string_len = strlen(string); // длина строки
			// printf("string_len: %d\n", string_len);
			for (int j = 0;  j < string_len; j++) // записываем слово
			{
				// printf("in i: %d\n", i);
				// printf("string[j]: %c\n", string[j]);
				if (strchr(chars,string[j]) != NULL)
				{
					// printf("tmp 2: %c\n", ptr[i+j]);
					tmp[i+j] = string[j];
				}
				else
					secret_count++;
				// printf("tmp 2: %c\n", ptr[i+j]);
			}
			i += 2;
			// printf("in i: %d\n", i);
			k = strlen(tmp);
			// printf("k: %d\n", k);
			// printf("after tmp:%s\n", ptr);
		}

		if(format[i] == '%' && format[i+1] == 'l')
		{
			x = va_arg(argptr, long long int); // взяли число
			itoa(x,x_str,16);
			llx_len = strlen(x_str); // длина строки с числом
			// printf("string_len: %d\n", string_len);
			for (int j = 0;  j < llx_len; j++) // записываем число
			{
				// printf("in i: %d\n", i);
				// printf("string[j]: %c\n", string[j]);
				if (strchr(chars,x_str[j]) != NULL)
				{
					// printf("tmp 2: %c\n", ptr[i+j]);
					tmp[i+j] = x_str[j];
				}
				else
					secret_count++;
				// printf("tmp 2: %c\n", ptr[i+j]);
			}
			i += 3;
			// printf("in i: %d\n", i);
			k = strlen(tmp);
			// printf("k: %d\n", k);
			// printf("after tmp:%s\n", ptr);
		}

		else
		{
			// printf("-----------------------\n");	
			// printf("i: %d\n", i);
			// printf("l: %d\n",string_len );
			// printf("%c\n", format[i]);
			tmp[k++] = format[i];
			//printf("tmp 1: %c \n", tmp[i+string_len]);
		}
		//k++;
	}

	va_end(argptr);

	if (strlen(tmp) < n)
		return strlen(tmp);
	else
		return n;
}
