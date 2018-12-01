
#include <stdio.h>
#include <math.h>

float srednee(FILE *f, int *count) // среднее арифметическое
{
    float sum = 0;
    float num;
    float sr;
    *count = 0; // если присвоить "count = 0" появится ошибка "segmentation fault"
    while (fscanf(f, "%f", &num) == 1)
    {
        sum += num;
        *count += 1;
    }
    sr = sum/(*count);

    return sr;
}

float dispersion(FILE *f, int c, float s) // дисперсия
{
    float sum = 0;
    float d;
    float disp;
    float deviation;
    float num;
    while (fscanf(f, "%f", &num) == 1)
    {
        d = num - s;
        deviation = pow(d,2);
        sum += deviation;
    }
    disp = sum/c;
    return disp;

}


int main(int argc, char **argv)
{
  FILE *f;
  int c;
  float num;
  float s;
  float d;

  if (argc != 2) // проверка на наличие файла в команде
 {
     fprintf(stderr, "No such file\n");
      return -1;
 }

  f = fopen(argv[1], "r");
  if (f == NULL) // проверка на успешное открытие файла
  {
      fprintf(stderr, "Could not open file\n");
      return -2;
  }
  else
  {
      if (fscanf(f, "%f", &num) == 1) // проверка на пустой файл
          // если не обновить файл после проверки, то в функцию попадет файл без первой цифры
      {
          rewind(f);
          s = srednee(f,&c);
          fclose(f);
          f = fopen(argv[1], "r");
          d = dispersion(f,c,s);
          fclose(f);
          printf("Dispersion: %f", d);
      }

      else
      {
          printf("File is emty!!!");
      }

  }
  return 0;

}
