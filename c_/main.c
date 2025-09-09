#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nl()
{
    printf("\n");
}

int *newArr(const int len)
{
    return (int *)malloc(len * sizeof(int));
}

void printArr(int *arr, int len)
{
    printf("{ ");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("}\n");
}

int lenOfNum(int n)
{
    if (n == 0)
        return 1;
    return (int)log10(n) + 1;
}

int *partitionNumIntArr(int n)
{
    int numSize = lenOfNum(n);
    int *arr = newArr(numSize);

    if (n == 0)
    {
        arr[0] = 0;
        return arr;
    }
    for (int i = 0, temp = n; temp; i++, temp /= 10)
    {
        arr[numSize - i - 1] = temp % 10;
    }
    return arr;
}

void p1(int n)
{
    int *arr = partitionNumIntArr(n);
    int numLen = lenOfNum(n);
    for (int i = 0; i < numLen; i++)
    {
        for (int j = i; j < numLen; j++)
        {
            for (int k = i; k <= j; k++)
            {
                printf("%d ", arr[k]);
            }
            nl();
        }
    }
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    int sqrtNum = (int)sqrt(n);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void p2(int n)
{
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            isPrime(k) ? printf("%d ", k)
                       : printf("* ");
            k++;
        }

        nl();
    }
}

void p3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("* ");
        nl();
    }
}

void p4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            printf("* ");
        nl();
    }
}

void p5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int s = 1; s < n - i; s++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        nl();
    }
}

void p6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < i; s++)
            printf(" ");
        for (int j = i; j < n; j++)
        {
            printf("* ");
        }
        nl();
    }
}

void p7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < n - i - 1; s++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        nl();
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int s = 0; s <= i; s++)
        {
            printf(" ");
        }
        for (int j = n - 1; j > i; j--)
        {
            printf("* ");
        }
        nl();
    }
}

void p8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        nl();
    }
}

void p9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        printf("*");

        for (int s = 0; s < 2 * (n - i) - 3; s++)
        {
            printf(" ");
        }

        if (i != n - 1)
            printf("*");

        nl();
    }
}

void p10(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || j == n - i - 1)
                printf("* ");
            else
                printf("  ");
        }
        nl();
    }
}

void p11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        nl();
    }
}

void p12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int s = n - i; s > 0; s--)
            printf(" ");
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        nl();
    }
}

void p13(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", j);
        }
        nl();
    }
}

int getSecondLargest(int *arr, int n)
{
    int firstMax = INT_MIN, secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstMax)
        {
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] != firstMax)
        {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int *removeDuplicates(int *arr, int n, int *new_size)
{
    int *temp = (int *)malloc(n * sizeof(int));
    *new_size = 0;

    for (int i = 0; i < n; i++)
    {
        int is_dup = 0;
        for (int j = 0; j < *new_size; j++)
        {
            if (arr[i] == temp[j])
            {
                is_dup = 1;
                break;
            }
        }
        if (!is_dup)
        {
            temp[*new_size] = arr[i];
            (*new_size)++;
        }
    }
    return temp;
}

void hashMappingSum(int *arr, int n, int target)
{
    int hash[100000] ={0};

    for (int i = 0; i < n; i++)
    {
        int diff = target - arr[i];
        if (diff >= 0 && hash[diff] > 0)
        {
            printf("%d,%d\n", arr[i], diff);
        }

        hash[arr[i]]++;
    }
}
char *my_strstr(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char *)haystack; // Empty needle matches at the beginning
    }

    for (const char *p = haystack; *p != '\0'; p++) {
        const char *h = p;
        const char *n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)p; // Found full match
        }
    }

    return NULL; // No match found
}
int main()
{
    // int n;
    // scanf("%d", &n);

    // p13(n);
    // p12(n);
    // int * arr = newArr(5);
    // for (int i = 0; i < 5; i++) {
    //     arr[i] = i;
    // }
    //
    // printArr(arr, 5);
    //
    // free(arr);
    // int s1 = sizeofNum(1);
    // int s2 = sizeofNum(0);
    // printf("%d %d\n",s1,s2);

    // p1(n);

    // p2(n);
    // p3(n);
    // p4(n);
    // p5(n);
    // p6(n);
    // p7(n);

    // p8(n);
    // p9(n);
    // p10(n);
    // p11(n);

    // int arr[] = {1, 2, 3, 2, 1, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int new_size;

    // int *unique = removeDuplicates(arr, n, &new_size);

    // printf("Unique elements: ");
    // for (int i = 0; i < new_size; i++)
    // {
    //     printf("%d ", unique[i]);
    // }
    // printf("\n");

    // free(unique);

    return 0;
}

