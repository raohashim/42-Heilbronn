#include <stdarg.h>
#include <stdio.h>

int ft_sum(int n, ...)
{
    int total = 0; // To get sum
    int i = 0; // Loop iterator
    // ap points to the first argument whihc is n
    va_list ap; // argument pointor (indicate no. of arguments) 

    // This is used to help to change the strat of our list. for app to next number.
    // from 5 to 1
    va_start (ap, n);

    printf("The value of n is : %d \n", n);
    while ( i < n)
    {
        // printf("Value of i : %d \n", va_arg(ap, int)); // va_arg it fetches the next argument of TYPE INDICATED
        total += va_arg(ap,int);
        i++;
    }

    return (total);
}

int main()
{
    int result;
                // The 5 is flage here           These are the actual arguments
    result = ft_sum(5,                           1,2,3,4,5);
    printf("The sum of the numbers is : %d", result);

    return (0);
}