#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "functions.h"


int my_snprintf(char *buf, int n, char *format, ...)
{
	int count;
	va_list argptr;
	va_start(argptr, format);

	count = vsnprintf(buf,n,format,argptr);

	va_end(argptr);
	return count;
}	
