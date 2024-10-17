// Create a program called CountUpBy5.
// • Input: The program should accept a positive integer 𝑛 from the user as input. If the given
// input is not a positive input it should prompt the user to retry
// • Hint: use a While-loop for this
// • Output: The program should then count all numbers from 0 up to 𝑛 that are multiples of 5
// and print them out on a single line on the screen.
// • Hint: use a For-loop or a While-loop for this

#include <stdio.h>
int main()
{

    int intputUser = 10;
    puts("Enter a positive number: ");
    scanf("%d", &intputUser);

    while (intputUser <= 0)
    {

        printf("Please enter a positive number: ");
        scanf("%d", &intputUser);
    }

    for (int outputUser = 0; outputUser <= intputUser; outputUser += 5)
    {

        printf("%d ", outputUser);
    }
    return 0;
}