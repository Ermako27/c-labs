#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strreverse(char* begin, char* end) {
	
	char aux;
	while(end>begin)
	{
		aux=*end;
		*end--=*begin; 
		*begin++=aux;
	}
	
}
	
void itoa(int value, char* str, int base) {
	
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

void main(void)
{
// тепличный тест, 16 число
    char buf1[100];
    long long int a = 0xd;
    snprintf(buf1,20, "%llx", a);
    printf("test1: %s\n", buf1);

// тепличный тест, 10 число
    char buf2[100];
    long long int b = 13;
    snprintf(buf2,20, "%llx", b);
    printf("test2: %s\n", buf2);

//  ascii
    char buf3[100];
    long long int c = 'p';
    snprintf(buf3,20, "%llx", c);
    printf("test3: %s\n", buf3);

// тепличный тест, 8 число
    char buf4[100];
    long long int d = 01234;
    snprintf(buf4,20, "%llx", d);
    printf("test4: %s\n", buf4);

// отрицательное число
    char buf5[100];
    long long int e = -0xffffffffffffffff;
    snprintf(buf5,20, "%llx", e);
    printf("test5: %s\n", buf5);


// Ограниченная емкость в snprinf
    char buf6[100];
    long long int f = 0xffffffffffffffff;
    snprintf(buf6,20, "%lld", f);
    printf("test6: %s\n", buf6);


    char st[100];
    long long int t = 'p';
    itoa(t, st, 16);
    printf("st: %s\n", st);
}