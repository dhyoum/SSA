#include <stdio.h>
#include "perf.h"

#define MAX 1000

unsigned long long array[MAX];

unsigned long long fibonacci(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;

    if (array[n]) return array[n];
    array[n] = fibonacci(n-1) + fibonacci(n-2);

    return array[n];
}

unsigned long long fibonacci2(int n)
{
    if (n==0) return 0;
    if (n==1 || n==2) return 1;

    if (array[n]) return array[n];

    int k = (n & 1) ? (n+1)/2 : n/2;
    array[n] = (n & 1) ? (fibonacci2(k)*fibonacci2(k) + fibonacci2(k-1)*fibonacci2(k-1)) 
           : (2*fibonacci2(k-1) + fibonacci2(k))*fibonacci2(k);     

    return array[n];
}

unsigned long long fibonacci3(int n)
{
    unsigned long long v_2=0, v_1=1;
    if (n == 0) return 0;
    if (n == 1) return 1;

    for (int i = 2; i <= n; i++)
    {
        unsigned long long temp = v_1 + v_2;
        v_2 = v_1;
        v_1 = temp;
    }
    return v_1;
}

int main()
{
	int N;
    scanf("%d", &N);
    printf("%llu\n", fibonacci(N));
    printf("%llu\n", fibonacci2(N));
    printf("%llu\n", fibonacci3(N));

    return 0;
}

