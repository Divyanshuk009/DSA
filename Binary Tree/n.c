// #include <stdio.h>

// int main()
// {
//     // int s = 1;
//     int i = 1;
//     for (; i++ < 5;)
//     {
//         printf("%d", i);
//     }

//     return 0;
// }

#include <stdio.h>

int main()
{
    int i;
    for (i = 5; i--;)

    {
        printf(" %d", i);
    }
    printf("\n");
    for (i = 5; --i;)

    {

        printf(" %d", i);
    }
    printf("\n");
    int a = 6, b = 4;
    while (a + b)
    {
        printf(" %d-%d ", a, b);
        a /= 2;
        b /= 3;
    }

    printf("\n");
    int n, count;
    printf("Enter:");
    scanf("%d", &n);
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    printf(" %d ", count);
    return 0;
}
