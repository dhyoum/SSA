#include <stdio.h>

#define MAX 10000

int array[MAX];

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void qsort(int data[], int left, int right)
{
    int pivot = data[(left+right)/2];

    int i = left;
    int j = right;

    while ( i <= j )
    {
        while ( data[i] < pivot )
            i++;
        while ( data[j] > pivot )
            j--;

        if ( i <= j )
            swap(data[i++], data[j--]);
    }
    if ( left < j)
        qsort(data, left, j);
    if ( i < right )
        qsort(data, i, right);
}

int main()
{
	int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        scanf("%d\n", &array[i]);

    qsort(array, 0, N);

    for(int i=0; i<N; i++)
        printf("%d) %5d\n", i, array[i]);

    return 0;
}

