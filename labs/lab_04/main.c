#include <stdio.h>
#define N 10
#define NO_ERR 0
#define NO_POS -1 //1
#define NO_NEG -2 //1
#define NO_MORE -1 //2
#define ALL_NEG -3 // 3
#define NO_CH -4
#define NO_NCH -5
#define NO_MAX_MIN -6
#define NO_SUCH_ELEM -7
#define NO3 -8


int func3(int *n, int *a)
{
    int i = 0;
    int j;
    int len = *n;
    int c = 0;
    for (i = 0; i < *n; i++) // количество положительных
    {
        if (*(a+i) > 0)
            c++;
    }
    i =0;
    while (i < *n)
    {
        if (a[i] < 0)
        {
            j = i;
            while (j < *n)
            {
                a[j] = a[j+1];
                j += 1;
            }
            *n -= 1;
        }
        else
        {
            i += 1;
        }
     }

    if ((c != 0) && (c!=len))
        return c;
    else if (c == len)
        return NO_NEG;
    else
        return ALL_NEG;
}


void print_mass(int a[], int size) // функция печати массива
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int func1(int *a, int n, int *sum, int *proizv) // сумма четных произведние нечетных
{
    int i;
    int cnt_1 = 0, cnt_2 = 0;
    *sum = 0;
    *proizv =  1;
    for (i=0; i < n; i++)
    {
       if (*(a+i) % 2 == 0)
       {
           *sum += *(a+i);
           cnt_1 += 1;
       }
       else
       {
           *proizv *= *(a+i);
           cnt_2 += 1;
       }
    }
    if (cnt_1 == 0)
        return NO_POS;

    if (cnt_2 == 0)
        return NO_NEG;
    if ((cnt_1 != 0) && (cnt_2 != 0))
        return NO_ERR;
    return 0;
}

float func2_1(int *a, int *count, int n) // перезапись элементов больших среднего ар.
{
    float c = 0.0;
    int i = 0;
    int sum = 0;
    float average = 0.0;
    *count = 0;
    for (i=0; i < n; i++) // нахождение среднего арифметического
    {
        sum += *(a+i);
        c += 1;
    }
    average = sum/c;

    for (i=0; i < n; i++) // размер массива с числами > среднего ар
    {
       if (*(a+i) > average)
           *count += 1;
    }
    return average;
}

void func2_2(int *a, int *b, float average,int n) // перезапись чисел больших ср.ар в новый массив
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a+i) > average)
        {
            *(b+k) = *(a+i);
            k += 1;
        }
    }
}

/*
int func3(int n, int *(a)) // не работает -1 -1 1 1 -1 -1
{
    int len = n;
    int i, j;
    int c = 0;
    int k = n;

    for (i = 0; i < n; i++)
    {
        if (*(a+i) < 0)
            c++;
    }
    for (i = 0; i < k; i++)
    {
        if (*(a+i) < 0)
        {
            k--;
            for (j = i; j < k; j++)
                *(a+j) = *(a+j+1);
            i--;
        }
    }
    if ((c != 0) && (c!=len))
        return c;
    else if (c == len)
        return ALL_NEG;
    else
        return NO_NEG;
}

int func3_1(int *a, int n) // вычисление размера массива с положительными значениями из исходного
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a+i) >= 0)
            count += 1;
    }
    return count;
}

int func3_2(int *a, int *b, int n) // создание массива без отрицательных элементов
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a+i) >= 0)
        {
            *(b+k) = a[i];
            k += 1;
        }
    }

    if (k == 0)
        return NO_NEG;

    return 0;
}
*/

int func_4(int n, int *a, int number)
{
    int i, j, z;
    int sum = 0;
    int c = 0; // переполнение исходного массива

    for (i = 0; i < n; i++)
    {
        if (*(a+i) == number)
            c += 1;
    }

    if (c == 0)
        return NO_SUCH_ELEM;
    else
    {
        for (i = 0; i < n; i++)
        {
            if (*(a+i) == number)
            {
                *(a+n+1) = sum;
                for (j = n + 1; j > i + 1; j--)
                {
                    z = *(a+j);
                    *(a+j) = *(a+j-1);
                    *(a+j-1) = z;
                }
                sum += *(a+i);
                n++;
                i++;
            }
            sum += *(a+i);
        }
        return c;
    }
}

//void func5(int a[], int *max_ch, int *min_nch)
int func5(int *a, int n) // обмен максимального четного и минимального нечетного
{
    int i = 0;
    int max_ch;
    int min_nch;
    int index1 = 0, index2 = 0;
    int flag1 = 0, flag2 = 0;
    int t;


    for (i = 0; i < n; i++)
    {
        if ((*(a+i) % 2 == 0) && (flag1 == 0))
        {
            max_ch = *(a+i);
            flag1 = 1;
            index1 = i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if ((*(a+i) % 2 != 0) && (flag2 == 0))
        {
            min_nch = *(a+i);
            flag2 = 1;
            index2 = i;
        }
    }
    /*
    while ((flag1 == 0) || (flag2 == 0)) // нахождение первого четного и нечетного элемента для сравнения
    {
        if ((*(a+i) % 2 == 0) && (flag1 == 0))
        {
            max_ch = *(a+i);
            flag1 = 1;
            //index1 = i;
        }
        else if ((*(a+i) % 2 != 0) && (flag2 == 0))
        {
            min_nch = *(a+i);
            flag2 = 1;
            //index2 = i;
        }
        i++;
    }
    */

   // printf("%d %d", flag1, flag2);

    if (flag1 == 0)
        return NO_CH;
    else if (flag2 == 0)
        return NO_NCH;
    else
    {
        for (i = 0; i < n; i++) // поиск максимального и минимального
        {
            if ((*(a+i) % 2 == 0) && (*(a+i) > max_ch))
            {
                max_ch = *(a+i);
                index1 = i;
            }
            if ((*(a+i) % 2 != 0) && (*(a+i) < min_nch))
            {
                min_nch = *(a+i);
                index2 = i;
            }
        }

        t = a[index1]; // обмен
        a[index1] = a[index2];
        a[index2] = t;
        return 0;
    }
printf("%d %d", flag1, flag2);
}

void func6(int *a, int n) // не работает 3 -3 3
{
    int i = 0;
    int max_el;
    int index;
    int sum = 0;
    int flag = 0;
    int count = 0;
    while (flag == 0) // нахождение первого элемента кратного 3 для сравнения
    {
        if (*(a+i) % 3 == 0)
        {
            max_el = *(a+i);
            flag = 1;
            index = i;
        }
        //printf("m: %d", max_el);
        i++;
    }

    for (i = 0; i < n; i++) // нахождение суммы и максимального элемента
    {
        if ((*(a+i) % 3 == 0) && (*(a+i) > max_el))
        {
            max_el = *(a+i);
            index = i;

        }
    }
    for (i = 0; i < n; i++)
    {
        if ((*(a+i) % 10 == 3) ||(*(a+i) % 10 == -3))
        {
            count += 1;
            sum += *(a+i);
        }
    }
    if (count != 0)
        *(a+index) = sum;

}

//void func7(int a[], int *max_index, int *min_index)
int func7(int a[], int n) // сортировка между максимальным и минимальным
{
    int min = a[0];
    int max = a[0];
    int max_index = 0, min_index = 0;
    int t;
    int k = 0;
    for (int i = 0; i < n; i++) // нахождение максимального и минимального
    {
        if (a[i] > max)
        {
            max = a[i];
            max_index = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            min_index = i;
        }

        if (a[i] == a[0])
            k++;
    }

    if (k == n)
        return NO_MAX_MIN;
    else
    {
        if (min_index > max_index) // чтобы отсчет начинался всегда с меньшего
        {
            t = min_index;
            min_index = max_index;
            max_index = t;
        }

        for(int i = min_index; i < max_index + 2; i++) { // сортировка
            for(int j = min_index; j < max_index + min_index - i; j++) {
                if(a[j] > a[j+1]) {
                    int tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                }
            }
        }
        return 0;
    }
}






int main(void)
{
    int err1; // 1
    int err3; // 3
    int err5; //5
    int err7;//7
    int sum, proizv; // 1
    int i = 0;
    int size2; // 2
    float average; // 2
    //int size3; // 3
    int number; // 4
    int c;
    int function;
    int len;
    int q;
    printf("Input len of array: ");
    if ((scanf("%d", &len) != 1) || (len < 0))
    {
        printf("Wrong input!!!");
    }
    else
    {
        int array[len];
        printf("Input array: ");
        for (i=0; i < len; i++)
        {
            q = scanf("%d", &array[i]);
        }

       if (q == 1)
       {

            printf("What function do you want to test, input number: ");
            if (scanf("%d", &function) == 1)
            {
                if (function == 1)
                {
                    err1 = func1(&array[0],len, &sum, &proizv); // 1
                    if (err1 == NO_POS)
                    {
                        printf("Sum: no elements\n");
                        printf("Proizv: %d", proizv);
                    }
                    else if (err1 == NO_NEG)
                    {
                        printf("Sum: %d\n", sum);
                        printf("Proizv: no elements");
                    }
                    else if (err1 == NO_ERR)
                    {
                        printf("Sum: %d\n", sum);
                        printf("Proizv: %d", proizv);
                    }
                }
                else if (function == 2)
                {
                    average = func2_1(array, &size2,len); // 2
                    int new_array2[size2];// 2
                    func2_2(&array[0], &new_array2[0], average,len);// 2
                    printf("average of array: %f\n", average);// 2
                    //printf("new array: ");// 2
                    if (size2 != 0)
                    {
                        printf("New array: ");
                        print_mass(new_array2, size2);// 2
                    }
                    else
                        printf("New array: no elements more than %f", average);
                }
                else if (function == 3)
                {
                    err3 = func3(&len, &array[0]);
                    if (err3 == NO_NEG)
                    {
                        printf("No negative elements");
                    }
                    else if (err3 == ALL_NEG)
                    {
                        printf("Empty, all elements are negative");
                    }
                    else
                    {
                        printf("New array: ");
                        print_mass(array, err3);
                    }
                    /*
                    size3 = func3_1(&array[0], len); // 3
                    int new_array3[size3]; // 3
                    err3 = func3_2(&array[0], &new_array3[0], len); // 3
                    printf("first array: "); // 3

                    if (err3 != NO_NEG)
                    {
                        print_mass(&array[0], len); // 3
                        printf("array without negative: "); // 3
                        print_mass(new_array3, size3); // 3
                    }
                    else
                    {
                        print_mass(&array[0], len); // 3
                        printf("No negative elements");
                    } */
                }
                else if (function == 4)
                {
                    printf("Ipnput integer number: ");
                    if (scanf("%d", &number) == 1)
                    {
                        c = func_4(len, &array[0], number);
                        if (c == NO_SUCH_ELEM)
                            printf("No such element");
                        else
                        {
                            printf("Array: ");
                            print_mass(array,len+c);
                        }
                    }
                    else
                    {
                        printf("Wrong Input!!!");
                    }
                }

                else if (function == 5)
                {
                    printf("first array: "); // 5
                    print_mass(array, len); // 5
                    err5 = func5(&array[0], len); // 5
                    if (err5 == NO_CH)
                    {
                        printf("No elements / 2 = 0\n");
                        printf("Array: ");
                        print_mass(array,len);
                    }
                    else if (err5 == NO_NCH)
                    {
                        printf("No elements / 2 = 1\n");
                        printf("Array: ");
                        print_mass(array,len);
                    }
                    else
                    {
                        printf("new array: "); // 5
                        print_mass(array, len); // 5
                    }
                }
                else if (function == 6)
                {   
                    printf("first array: "); // 6
                    print_mass(array, len); // 6
                    func6(&array[0],len); // 6
                    printf("new array: "); // 6
                    print_mass(array, len); // 6
                }
                else if (function == 7)
                {
                    printf("first array: "); // 7
                    print_mass(array, len); // 7
                    err7 = func7(array,len); // 7
                    if (err7 == NO_MAX_MIN)
                    {
                        printf("No max or min\n");
                        printf("Array: ");
                        print_mass(array, len); // 7
                    }
                    else
                    {
                        printf("new array: "); // 7
                        print_mass(array, len); // 7
                    }
                }

            }
            else{
                    printf("Wrong input!!!");
                }
        }
       else
       {
           printf("Wrong input!!!");
       }
    }
        return 0;
}


