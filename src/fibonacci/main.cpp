#include <stdio.h>

#define MAX 90

int array[MAX];

int fibonacci(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;

    if (array[n]) return array[n];
    array[n] = fibonacci(n-1) + fibonacci(n-2);

    return array[n];
}

int main()
{
	int N;
    scanf("%d", &N);
    printf("%d\n", fibonacci(N));

    return 0;
}

