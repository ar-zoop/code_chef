#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int a, y, sum, temp;
    for (int i = 1; i <= x; i++)
    {
        scanf("%d", &a);
        temp = a % 10;
        while (a > 0)
        {
            y = a % 10;
            a = a / 10;
        }
        sum=temp+y;
        printf("%d\n", sum);
    }

    return 0;
}

