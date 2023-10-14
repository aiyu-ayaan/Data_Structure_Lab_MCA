#include <stdio.h>
#include <stdlib.h>

void interative_fibo(int n)
{
    // Loop n times.
    int i, a = 0, b = 1, c, sum = 0;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", a);

        // The next element in the sequence is the sum of the previous two elements.
        c = a + b;

        // The next element in the sequence is the sum of the previous two elements.
        a = b;
        b = c;
    }
}

int fib(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int result = fib(n - 1) + fib(n - 2);
        return result;
    }
}

void printFibonacciSeries(int n) {
    if (n <= 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
}

void main() {
    int n = 100;
    // fibo(n);
    // // printf("\n");
    printFibonacciSeries(n);
}
