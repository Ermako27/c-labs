#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test(int capacity)
{
	char buf[12]; 
	//long long unsigned int a = 0x21f;
	//char b = (char)a;
	snprintf(buf, capacity, "%s", "12345678909");
	printf("capacity = %d, buf = %s, length = %d\n", 
		capacity, buf, (int)strlen(buf));

	// printf("test_mem adres: %p\n", &(test_mem));

	// for (int i = 0; i < 11; i++)
	// {
	// 	printf("value: %c adres: %p\n",buf[i], &(buf[i]));
	// }

}


int main()
{
    // test(1);
    // test(2);
    // test(3);
    // test(4);
    // test(5);
    // test(6);
    // test(7);
    // test(8);
    // test(9);
    // test(10);
    // test(11);
    test(11);
    // test(20);
    return 0;
}
