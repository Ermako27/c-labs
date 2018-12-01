#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include <iostream>



void replace(char *str,char *a,char *b,char buffer[])
{
    int i,j,pos=0;
    for(i=0;str[i];i++)
    {
        for(j=0;str[i+j]&&a[j];j++)   //начинается ли с i-ой позиции строка a
        {
            if(str[i+j]!=a[j]) 
                break;
        }
        if(!a[j])  //если a[j]=0, то мы дошли до конца строки a
        {
            i+=j-1;  //в j у нас длина стоки a, которую мы перепрыгиваем
            for(j=0;b[j];j++) 
                buffer[pos++]=b[j];  //на место стоки a ставим строку b
        }
        else
        {
            buffer[pos++]=str[i];   //просто копируем символ
        }
        buffer[pos]='\0';  //ставим конец строки
    }
    strcpy(str,buffer);  //копируем в первоначальную строку
}


void test_replace(void)
{
    int err_count = 0;

// тест заменяемая строка равна по длине замене

    char str1[100]="my destiny, not my destiny,mydestiny";
    char result1[100] = "bb destiny, not bb destiny,bbdestiny";
    char *rp_str1 = str1;
    char a1[]="my",b1[]="bb";
    char *rpa1 = a1;
    char *rpb1 = b1;
    char buffer1[200];
    replace(rp_str1, rpa1, rpb1, buffer1);

    if (strcmp(rp_str1, result1) != 0)
    {
        err_count++;
        printf("replace: %s\n", rp_str1);
        printf("result: %s\n", result1);
    }


// тест заменяемая строка короче замены

    char str2[100]="my destiny, not my destiny,mydestiny";
    char result2[100] = "your destiny, not your destiny,yourdestiny";
    char *rp_str2 = str2;
    char a2[]="my",b2[]="your";
    char *rpa2 = a2;
    char *rpb2 = b2;
    char buffer2[200];
    replace(rp_str2, rpa2, rpb2, buffer2);

    if (strcmp(rp_str2, result2) != 0)
    {
        err_count++;
        printf("replace: %s\n", rp_str2);
        printf("result: %s\n", result2);
    }


// тест заменяемая строка длинее замены

    char str3[100]="my destiny, not my destiny,mydestiny";
    char result3[100] = "my purp, not my purp,mypurp";
    
    char *rp_str3 = str3;
    char a3[]="destiny",b3[]="purp";
    char *rpa3 = a3;
    char *rpb3 = b3;
    char buffer3[200];
    replace(rp_str3, rpa3, rpb3, buffer3);

    if (strcmp(rp_str3, result3) != 0)
    {
        err_count++;
        printf("replace: %s\n", rp_str3);
        printf("result: %s\n", result3);
    }

// замена на пустую строку
    char str4[100]="my destiny, not my destiny,mydestiny";
    char result4[100] = "my  , not my  ,my ";
    
    char *rp_str4 = str4;
    char a4[]="destiny",b4[]=" ";
    char *rpa4 = a4;
    char *rpb4 = b4;
    char buffer4[200];
    replace(rp_str4, rpa4, rpb4, buffer4);

    if (strcmp(rp_str4, result4) != 0)
    {
        err_count++;
        printf("replace: %s\n", rp_str4);
        printf("result: %s\n", result4);
    }

    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}


int main(void)
{    
    test_replace();
    return 0;
}


