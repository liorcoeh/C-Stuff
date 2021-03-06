/*
 * Building a function that will create pairs out of given names:
 * Each pair will be twice (one time A and B, one time B and A).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE (8)
#define BIG_SIZE (3000)
#define COUNT (30)



void InitializeArray(int arr[], int size);
void PrintArrays(int arr1[], int arr2[], int size);
int SumArray(int arr[], int size);

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int counter = COUNT;
    int count = 0;
    int check = -1;
    
    int enter1 = 0;
    int enter2 = 0;

    int arr1[SIZE] = {0};
    int arr2[SIZE] = {0};
    int holding_arr1[BIG_SIZE] = {0};
    int holding_arr2[BIG_SIZE] = {0};

    int first = -1;
    int second = -1;

    InitializeArray(arr1, SIZE);
    InitializeArray(arr2, SIZE);

    srand(time(NULL));

    while (56 > k)
    {
     
         while (0 != check)
         {
              check = -1;
              enter1 = rand() % SIZE;
              enter2 = rand() % SIZE;

              for (i = 0; i < SIZE; ++i)
              {
                   if (0 == arr1[i])
                   {
                       ++counter;
                   }
              }

              if (11 == counter)
              {
                  for (i = 0; i < SIZE; ++i)
                  {
                      if (0 != arr1[i])
                      {
                          enter1 = arr1[i];
                      }
                      if (0 != arr2[i])
                      {
                          enter2 = arr2[i];
                      }
                  }
              }


              /* Will give the same value */
              if (enter1 == enter2)
              {
                  check = -2;
              }
              /* One of the values equals zero */
              else if (0 == arr1[enter1] || 0 == arr2[enter2])
              {
                  check = -2;
              }

              for (j = 0; j < k; ++j)
              {
                  if (holding_arr1[j] == arr1[enter1] &&
                      holding_arr2[j] == arr2[enter2])
                  {
                      i = k;
                      for (i - count; i <= k; ++i)
                      {
                          holding_arr1[i] = 0;
                          holding_arr2[i] = 0;
                      }
                      
                      k = k - count;
                      count = 0;

                      InitializeArray(arr1, SIZE);
                      InitializeArray(arr2, SIZE);

                      check = -2;
                  }
                  
              }

              if (-1 == check)
              {
                  check = 0;
              }
              
         }

         holding_arr1[k] = arr1[enter1];
         holding_arr2[k] = arr2[enter2];

         arr1[enter1] = 0;
         arr2[enter1] = 0;

         arr1[enter2] = 0;
         arr2[enter2] = 0;

         ++count;
         check = -1;
         ++k;

         if (0 == SumArray(arr1, SIZE))
         {
             InitializeArray(arr1, SIZE);
             InitializeArray(arr2, SIZE);
             count = 0;
         }

    }

    PrintArrays(holding_arr1, holding_arr2, BIG_SIZE);

    printf("%d\n", k);

    return (0);
}


void InitializeArray(int arr[], int size)
{
    int i = 0;

    for (i = 0; i < size; ++i)
    {
        arr[i] = i + 1;
    }
}

void PrintArrays(int arr1[], int arr2[], int size)
{
    int i = 0;
    int j = 0;
    int counter = 0;

    for (i = 0; i < size; ++i)
    {
        for (j = i + 1; j < size; ++j)
        {
            if (arr1[i] == arr1[j] && arr2[i] == arr2[j])
            {
                arr1[j] = 0;
                arr2[j] = 0;
            }
        }
        if (arr1[i] == arr2[i])
        {
            ;
        }
        else
        {
            switch (arr1[i])
            {
            case (1):
                printf("Alistair Hudson / ");
                break;

            case (2):
                printf("Daria Korotkova / ");
                break;
            
            case (3):
                printf("Dmitry Neustroyev / ");
                break;

            case (4):
                printf("Ivanna Fleisher / ");
                break;

            case (5):
                printf("Kobi Rappaport / ");
                break;

            case (6):
                printf("Tehila (Laura) / ");
                break;

            case (7):
                printf("Shmuel Pablo Sinder / ");
                break;

            case (8):
                printf("Yurii Yashchuk / ");
                break;
            }

            switch (arr2[i])
            {
            case (1):
                printf("Alistair Hudson\n\n");
                break;

            case (2):
                printf("Daria Korotkova\n\n");
                break;
            
            case (3):
                printf("Dmitry Neustroyev\n\n");
                break;

            case (4):
                printf("Ivanna Fleisher\n\n");
                break;

            case (5):
                printf("Kobi Rappaport\n\n");
                break;

            case (6):
                printf("Tehila (Laura)\n\n");
                break;

            case (7):
                printf("Shmuel Pablo Sinder\n\n");
                break;

            case (8):
                printf("Yurii Yashchuk\n\n");
                break;
            }

            //printf("%d / %d\n", arr1[i], arr2[i]);
            ++counter;
        }
    }

    printf("Total is %d\n\n", counter);
}

int SumArray(int arr[], int size)
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return (sum);
}