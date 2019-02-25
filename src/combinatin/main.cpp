#include <stdio.h>

#define MAX 10000

void printOut(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int selected[MAX];
void Comb(int arr[], int N, int M, int depth, int start)
{
    if ( M == depth )
    {
        printOut(selected, M);
        return;
    }

    for(int i=start; i<N; i++)
    {
        selected[depth] = arr[i];
        // Comb(arr, N, M, depth+1, i); replitation
        Comb(arr, N, M, depth+1, i+1);
    }
}

int main()
{
    int N, M;
    scanf("%d, %d", &N, &M);

    int array[MAX];

    for(int i=0; i<N; i++)
        scanf("%d\n", &array[i]);

    Comb(array, 3, 2, 0, 0);

    return 0;
}
