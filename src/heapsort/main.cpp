#include <stdio.h>

#define MAX 10000

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void printOut(int arr[], int N)
{
    for(int i=0; i<N; i++)
        printf("%d) %5d\n", i, arr[i]);
}

void max_heapify(int arr[], int node, int N)
{
    int left = node*2+1;
    int right = left+1;
    int k = left;

    if ( arr[left] < arr[right] && right < N )
        k = right;
    if ( arr[node] < arr[k] && k < N )
    {
        swap(arr[node], arr[k]);
    }
        
    if ( k <= N/2 ) // top->down
        max_heapify(arr, k, N);
}

void build_heap(int arr[], int N)
{
    for(int i=N/2; i>=0; i--)
    {
       max_heapify(arr, i, N);
    }
}

void build_heap2(int arr[], int N)
{
    for(int i=N/2; i<N; i++)
    {
        int c = i;
        do {
            int root = (c-1)/2;
            if ( arr[root] < arr[c] )
                swap(arr[root], arr[c]);
            c = root;
        } while ( c !=0 );
    }
}

void heap_sort(int heap[], int N)
{
    for (int i = N-1; i>=0; i--)
    {
        swap(heap[0], heap[i]);
        max_heapify(heap, 0, i);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int array[MAX];

    for(int i=0; i<N; i++)
        scanf("%d\n", &array[i]);

    printOut(array, N);

    build_heap(array, N);
    printf("after heapify\n");
    printOut(array, N);

    heap_sort(array, N);
    printf("after sort\n");
    printOut(array, N);

    return 0;
}

