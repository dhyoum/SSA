#include <stdio.h>

#define MAX 10000

void printOut(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int selected[MAX];
int used = 0;
void Perm(int arr[], int N, int M, int depth)
{
    if ( M == depth )
    {
        printOut(selected, M);
        return;
    }

    for(int i=0; i<N; i++)
    {
        // if ( used & (1<<i) ) continue; repetition

        selected[depth] = arr[i];
        used |= (1<<i);
        Perm(arr, N, M, depth+1);
        used &= ~(1<<i);
    }
}

int main()
{
    int N, M;
    scanf("%d, %d", &N, &M);

    int array[MAX];

    for(int i=0; i<N; i++)
        scanf("%d\n", &array[i]);

    Perm(array, N, M, 0);

    return 0;
}
