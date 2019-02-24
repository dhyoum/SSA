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

void merge(int array[], int start, int mid, int end)
{
    int temp[MAX];

    for(int i=start; i<=end; i++)
    {
        temp[i] = array[i];
    }

    int part1 = start;
    int part2 = mid+1;
    int index = start;

    while (part1 <= mid && part2 <= end)
    {
        if (temp[part1] < temp[part2])
            array[index++] = temp[part1++];
        else
            array[index++] = temp[part2++];
    }

    for (int i=part1; i <= mid; i++)
    {
        array[index++] = temp[i];
    }
}

void merge_sort(int array[], int start, int end)
{
    if ( start >= end ) return;

    int mid = (start + end)/2;
    int part1 = start;
    int part2 = mid+1;

    merge_sort(array, part1, mid);
    merge_sort(array, part2, end);

    merge(array, start, mid, end);
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        scanf("%d\n", &array[i]);

    merge_sort(array, 0, N-1);

    for(int i=0; i<N; i++)
        printf("%d) %5d\n", i, array[i]);

    return 0;
}

