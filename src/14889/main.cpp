#include <stdio.h>

int data[4][4] = {
    {0, 1, 2, 3},
    {4, 0, 5, 6},
    {7, 1, 0, 2},
    {3, 4, 5, 0}
};

int N = 4;

int select[1<<4];

int pp[8];

void dfs(int index, int sum, int n)
{
    if ( n == 2 )
    {
        /*
        for (int i = 0; i < n; ++i) {
           printf("%d ", pp[i]); 
        }
        */
        printf("sum = %d\n", sum);
        return;
    }

    for(int i=n; i<N; i++)
    {
        if ( select[i] ) continue;

        select[i] = 1;

        int start = 0;

        dfs(i, sum+data[i], n+1);
        select[i] = 0;
    }
}

int main()
{
    dfs(0, 0, 0);

    return 0;
}

