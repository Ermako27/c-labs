#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OK 0
#define INVALID_PARAM -1
#define ERR_NO_DATA -2



#define SWAP(a, b, size)                                                      \
      do                                                                              \
        {                                                                              \
          size_t __size = (size);                                                      \
          char *__a = (a), *__b = (b);                                              \
          do                                                                      \
            {                                                                      \
              char __tmp = *__a;                                                      \
              *__a++ = *__b;                                                      \
              *__b++ = __tmp;                                                      \
            } while (--__size > 0);                                                      \
        } while (0)




int compare(const void* p, const void* q)
{
  const float *a = p;
  const float *b = q;
  return *a - *b;
}

int char_compare(const void* p, const void* q)
{
  const char *a = p;
  const char *b = q;
  return *a - *b;
}

int sort(void *pbase, size_t total, size_t size, int (*compare)(const void*, const void*))
{
    if ((int)total == 0)
      return ERR_NO_DATA;
    if (pbase == NULL || total == (size_t)NULL || size == (size_t)NULL || compare == NULL)
    {
      return INVALID_PARAM;
    }
    


    char *b = pbase;
    char *lo = b;
    char *hi = lo + total * size;
    char *new_el, *loc;

    for (lo = lo + size; lo < hi; lo += size)
    {
        new_el = lo;
        for (loc = lo - size; loc >= b; loc -= size)
        {
            if (compare(loc,new_el)> 0)
            {
                SWAP(loc,new_el,size);
            }
            new_el -= size;
        }
    }
    return OK;
}


void test_sort(void)
{
  int err_count = 0;
  int a1[] = {5,3,9,1,4,7};
  int a2[] = {};
  char a3[] = {'c', 'a', 'b'};
  if (sort(NULL, 6,sizeof(a1[0]),compare) != INVALID_PARAM)
  {
    printf("1\n");
    err_count++;
  }

  if (sort(a1, (size_t)NULL,sizeof(a1[0]),compare) != INVALID_PARAM && 
    sort(a1, (size_t)NULL,sizeof(a1[0]),compare) != ERR_NO_DATA)
  {
    printf("2\n");
    err_count++;
  }

  if (sort(a1, 6,(size_t)NULL,compare) != INVALID_PARAM)
  {
    printf("3\n");
    err_count++;
  }

  if (sort(a1, 6,sizeof(a1[0]),NULL) != INVALID_PARAM)
  {
    printf("4\n");
    err_count++;
  }

  if (sort(a2, 0,sizeof(a2[0]),compare) != ERR_NO_DATA)
  {
    printf("5\n");
    err_count++;
  }

  if (sort(a1, 6,sizeof(a1[0]),compare) != OK)
  {
    printf("6\n");
    err_count++;
  }
  if (sort(a3, 6,sizeof(a3[0]),compare) != OK)
  {
    printf("7\n");
    err_count++;
  }



  printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
}

int main(void)
{
    test_sort();
    return 0;
}