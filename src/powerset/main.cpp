#include <stdio.h>

int data[4] = {1,2,3,4};

void powerSet(int arr[], int size, int M)
{
    // 0 0 0 0
    for (int i = 1; i < 1<<size; i++)
    {
        for(int j=0; j<size;j++)
        {
            if (i & (1<<j))
                printf("%d", data[j]);
        }
        printf("\n");
    }
}

void ps(int info, int a, int b, int p)
{
    if ( a + b  == 4 )
    {
        printf("info = 0x%x a:%d , b:%d [p:%d]\n", info, a, b , p);
        return;
    }

    ps(info | 1<<p, a+1, b, p+1);
    ps(info, a, b+1, p+1);
}

int main()
{
    // powerSet(data, 4, 4);
    ps(0, 0, 0, 0);

    return 0;
}
