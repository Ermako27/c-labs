/*
Слайд 12
*/

struct date
{
    int day;
    int month;
    int year;
};

#define NAME_LEN 15

struct person
{
    char name[NAME_LEN+1];
    struct date birth;
};


int main(void)
{
    struct date today = {25, 9, 2017};

    struct date day = {25};

    /*
    struct date year = {, , 2017};
    // error: expected expression before ',' token
    */

    struct person rector = {"Aleksandrov", {7, 4, 1951}};

    struct date holidays[] = {{4, 11, 2017}, {5, 11, 2017}, {6, 11, 2017}};

    struct date year = {.year = 2017};

    struct date yesterday = {.year = 2017, .month = 9, .day = 24};

    (void) today;
    (void) day;
    (void) rector;
    (void) holidays;
    (void) year;
    (void) yesterday;
}