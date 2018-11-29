#include <stdio.h>

#define MAX 10000

int array[MAX];

int main()
{
	int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        scanf("%d\n", &array[i]);

    for(int i=0; i<N; i++)
        printf("%d) %5d\n", i, array[i]);

    return 0;
}

