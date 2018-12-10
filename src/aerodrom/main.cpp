#include <stdio.h>

#define MAX 300001

int array[MAX];

int main()
{
	int n, m;
    scanf("%d%d", &n, &m);
    long long lo = 0, hi = 0;
    for (int i=0; i<n; i++) 
    {
        scanf("%d", array+i);
        if ( hi < array[i] )
            hi = array[i];

    }

    hi *= m;
    while ( lo < hi )
    {
        long long mid = (lo + hi)/2;
        long long kol = 0;
        for(int i=0; i<n; i++)
        {
            kol += mid / array[i];
        }
        if ( kol < m ) 
            lo = mid+1;
        else
            hi = mid;
    }
    printf("%lld\n", lo);

    return 0;
}

