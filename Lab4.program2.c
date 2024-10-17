#include <stdio.h>
int main()
{

    double sum = 0;
    double num;
    do
    {
        printf("Enter a number (or 0 to exit): ");
        scanf("%lf", &num);
        sum += num;
        printf("Current sum: %.2lf\n", sum);
    } while (num != 0);
    printf("Final sum: %.2lf\n", sum);
}