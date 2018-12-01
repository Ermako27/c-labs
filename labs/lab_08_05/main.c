/*
проблема 1: при выделениии памяти под массив указателей прототип функции имеет вид
float** allocate_matrix_rows(int n, int m). объявление в main float *first_matrix.
ошибка assignment from incompatible pointer type. 

Решение: float **first_matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

#define OK 0
#define INCORRECT -1
#define UNEQUAL -2
#define NOT_SQUARE -3

int main(int argc, char **argv)
{
    FILE *f1;
    FILE *f2;
    float n1_f;
    float n2_f;
    int decision;

    int n1;
    int m1;
    int n2;
    int m2;
    int file_error1;
    int file_error2;



    printf("1 - sum\n2 - multiply\n3 - determinant\n\n");
    printf("Choose what you want to do (tap 1,2 or 3): ");
    scanf("%d", &decision);
    if (decision != 1 && decision != 2 && decision != 3)
    {
        printf("\nI dont know this comand:(\n");
        return 0;
    }
    if (decision == 1) // выбор - сумма
    {
        if (argc != 3) // провекра на правилное количество аргументов
        {
            printf("\nNot enough arguments!!!\n");
        }
        else 
        {
            f1 = fopen(argv[1], "r");
            f2 = fopen(argv[2], "r");
            if (f1 == NULL || f2 == NULL)
            {
                printf("\nCould not open file!!!\n");
                return 0;
            }
            else
            {
                if (fscanf(f1, "%f", &n1_f) != 1 || fscanf(f2, "%f", &n2_f) != 1)
                {
                    printf("\nEmpty file!!!\n");
                }

                else
                {
                    rewind(f1);
                    rewind(f2);
                    float *data1;
                    float *data2;
                    float *res;
                    int sum_error;


                    file_error1 = filtr(f1);
                    file_error2 = filtr(f2);

                    if (file_error2 != OK || file_error1 != OK)
                    {
                        printf("\nIncorrect data in file\n");
                        return 0;
                    }
                    else 
                    {
                        rewind(f1);
                        rewind(f2);
                        fscanf(f1,"%d",&n1);
                        fscanf(f1,"%d",&m1);
                        fscanf(f2,"%d",&n2);
                        fscanf(f2,"%d",&m2);
                        if (n1 != n2 || m1 != m2)
                        {
                            printf("\nNot equal size!!!\n");
                            return 0;
                        }
                        else
                        {
                            data1 = malloc(n1*m1*sizeof(float));
                            data2 = malloc(n2*m2*sizeof(float));
                            create_matrix(data1,f1);
                            create_matrix(data2,f2);
                            sum_error = sum(n1,m1, data1, data2, &res);
                            fclose(f1);
                            fclose(f2);
                            if (sum_error == OK)
                            {
                                printf("\n--------------------------------\n");
                                printf("first matrix:\n");
                                print_mass(data1, n1, m1);
                                printf("\n");
                                printf("second matrix:\n");
                                print_mass(data2, n2, m2);
                                printf("result of sum:\n");
                                print_mass(res, n1, m1);
                            }
                            free(data1);
                            free(data2);
                            free(res);
                        }
                    }
                }
            }
        }
    }

    else if (decision == 2)
    {
        if (argc != 3)
        {
            printf("\nNot enough arguments!!!\n");
        }
        else 
        {
            f1 = fopen(argv[1], "r");
            f2 = fopen(argv[2], "r");
            if (f1 == NULL || f2 == NULL)
            {
                printf("\nCould not open file!!!\n");
                return 0;
            }
            else
            {
                if (fscanf(f1, "%f", &n1_f) != 1 || fscanf(f2, "%f", &n2_f) != 1)
                {
                    printf("\nEmpty file!!!\n");
                }
                else
                {
                    rewind(f1);
                    rewind(f2);
                    float **data1_mult;
                    float **data2_mult;
                    float **res_mult;
                    int multy_error;


                    file_error1 = filtr(f1);
                    file_error2 = filtr(f2);

                    if (file_error2 != OK || file_error1 != OK)
                    {
                        printf("\nIncorrect data in file\n");
                        return 0;
                    }
                    else 
                    {
                        rewind(f1);
                        rewind(f2);
                        fscanf(f1,"%d",&n1);
                        fscanf(f1,"%d",&m1);
                        fscanf(f2,"%d",&n2);
                        fscanf(f2,"%d",&m2);
                        data1_mult = allocate_matrix_rows(n1,m1,f1);
                        data2_mult = allocate_matrix_rows(n2,m2,f2);
                        res_mult = alloc(n1,m2);
                        multy_error = multiply(n1,m1,data1_mult,n2, m2,data2_mult,res_mult);
                        fclose(f1);
                        fclose(f2);
                        printf("\n--------------------------------\n");
                        printf("first matrix:\n");
                        print_matrix(n1,m1,data1_mult);
                        printf("\n");
                        printf("second matrix:\n");
                        print_matrix(n2,m2,data2_mult);
                        if (multy_error == INCORRECT)
                        {
                            printf("\nWrong size of matrix!!!\n");
                            return 0;
                        }
                        else if (multy_error == OK)
                        {
                            printf("result of multiply:\n");
                            print_matrix(n1,m2,res_mult);
                        }
                        free_matrix_rows(data1_mult,n1);
                        free_matrix_rows(data2_mult,n2);
                        free_matrix_rows(res_mult,n1);

                    }
                }
            }  
        }     
    }   

    else if (decision == 3)
    {
        if (argc != 2)
        {
            printf("\nNot enough arguments!!!\n");
        }
        else 
        {
            f1 = fopen(argv[1], "r");
            if (f1 == NULL)
            {
                printf("\nCould not open file!!!\n");
                return 0;
            }
            else
            {
                if (fscanf(f1, "%f", &n1_f) != 1)
                {
                    printf("\nEmpty file!!!\n");
                }

                else
                {
                    rewind(f1);
                    float **data1_det;
                    int det_error;

                    file_error1 = filtr(f1);

                    if (file_error1 != OK)
                    {
                        printf("\nIncorrect data in file\n");
                        return 0;
                    }
                    else 
                    {
                        rewind(f1);
                        fscanf(f1,"%d",&n1);
                        fscanf(f1,"%d",&m1);
                        data1_det = allocate_matrix_rows(n1,m1,f1);
                        printf("\n--------------------------------\n");
                        printf("matrix:\n");
                        print_matrix(n1,m1,data1_det);
                        det_error = determ(data1_det,n1,m1);
                        fclose(f1);
                        if (det_error == INCORRECT)
                        {
                            printf("\nMatrix is not square!!!\n");
                            return 0;
                        }
                        else if (det_error != INCORRECT)
                        {
                            printf("determinant: %d\n", det_error);
                        }
                        free_matrix_rows(data1_det,n1);
                    }
                }
            }
        }
    }
}
