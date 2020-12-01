/*
 * Practicing different functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define SIZE (15)

/*void RandomArrInitialize(size_t arr[], size_t size);
void Prsize_tArr(size_t arr[], size_t size);
size_t Compare(const void * a, const void * b);
size_t AreTwoSumOfOne(size_t arr[], size_t size, size_t num);

size_t TwoMissingNumbers(size_t arr[], size_t size, size_t* first, size_t *second);
size_t SquaredEquasation (size_t b, size_t c);*/

void *Memset(void *str, int c, size_t n);
void *Memcpy(void *dest, const void * src, size_t n);

size_t main()
{
    size_t array1[SIZE] = {0};
    size_t num = 1;
    size_t first = 0;
    size_t second = 0;

    const char src[50] = "http://www.tutorialspoint.com";
    char dest[50];

    char str[50];

    system("clear");

    strcpy(dest,"Heloooo!!");
    printf("Before Memcpy dest = %s\n", dest);
    Memcpy(dest, src, strlen(src)+1);
    printf("After Memcpy dest = %s\n", dest);

    strcpy(str,"This is string.h library function");
    printf("%s\n", str);

    Memset(str,'$',7);
    printf("%s\n", str);

    
    /*prsize_tf("\n\n");

    RandomArrInitialize(array1, 100);

    Prsize_tArr(array1, 100);

    qsort(array1, SIZE, sizeof(size_t), Compare);

    Prsize_tArr(array1, SIZE);

    AreTwoSumOfOne(array1, SIZE, num);

    TwoMissingNumbers(array1, SIZE + 2, &first, &second);

    prsize_tf("first is: %d, second is: %d\n", first, second);*/

    return (0);
}

void *Memcpy(void *dest, const void *src, size_t n)
{
    int i = 0;

    if (NULL == dest || NULL == src)
    {
        return (dest);
    }
    
    for (i = 0; i < n; ++i)
    {
       *(char *)(dest + i) = *(char *)(src + i);
    }

    return (dest);
}

void *Memset(void *str, int c, size_t n)
{
    char *n_str = str;
    int i = 0;

    for (i = 0; i < n; ++i)
    {
        *n_str = c;
        ++n_str;
    }

    return (str);
}


/*size_t TwoMissingNumbers(size_t arr[], size_t n, size_t* first, size_t *second)
{
    size_t a1 = 0;
    size_t a2 = 0;
    size_t n_sum = 0;
    size_t n_multiply = 1;
    size_t arr_sum = 0;
    size_t arr_multiply = 1;
    size_t i = 0;

    for (i = 0; i < n; ++i)
    {
        n_sum += i + 1;
        n_multiply *= (i + 1);
        arr_sum += arr[i];
        arr_multiply *= arr[i];
    }

    prsize_tf("i = %d\n", i);
    prsize_tf("n_multiply = %d\n", n_multiply);

    n_sum += (i + 1);
    n_multiply *= (i + 1);
    ++i;
    n_sum += (i + 1);
    n_multiply *= (i + 1);

    prsize_tf("n_sum = %d\n", n_sum);
    prsize_tf("n_multiply = %d\n", n_multiply);
    prsize_tf("arr_sum = %d\n", arr_sum);
    prsize_tf("arr_multiply = %d\n", arr_multiply);


    a1 = SquaredEquasation (n_sum - arr_sum, n_multiply - arr_multiply);
    a2 = n_sum - arr_sum - a2;

    *first = a1;
    *second = a2;

    if (a1 == 0)
    {
        return (-1);
    }
    else
    {
        return (0);
    } 
}

size_t SquaredEquasation (size_t b, size_t c)
{
    size_t res1 = (-(b) + sqrt(pow(b, 2) - 4*c)) / 2;
    size_t res2 = (-(b) - sqrt(pow(b, 2) - 4*c)) / 2;

    prsize_tf("res1 = %d\n", res1);
    prsize_tf("res2 = %d\n", res2);


    if (res1 < 0)
    {
        return (res2);
    }
    else if (res2 > 0)
    {
        return (res1);
    }
    else
    {
        return (res1);
    }
}


void RandomArrInitialize(size_t arr[], size_t size)
{
    size_t i = 0;

    srand(time(NULL));

    for (i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
    }
}

void Prsize_tArr(size_t arr[], size_t size)
{
    size_t i = 0;

    for (i = 0; i < size; ++i)
    {
        prsize_tf("%d, ", arr[i]);
    }

    prsize_tf("\n\n");
}

size_t Compare(const void * a, const void * b) 
{ 
    return ( *(size_t*)a - *(size_t*)b ); 
}

size_t AreTwoSumOfOne(size_t arr[], size_t size, size_t num)
{
    size_t i = 0;
    size_t j = size - 1;

    while (i < j)
    {
        if (num == arr[i] + arr[j])
        {
            prsize_tf("%d + %d = %d\n\n", arr[i], arr[j], num);
            return (0);
        }
        else if (num > arr[i] + arr[j])
        {
            ++i;
        }
        else if (num < arr[i] + arr[j])
        {
            --j;
        }
    }
    prsize_tf("There are no two numbers that sum up to %d\n\n", num);
    return (1);
}*/