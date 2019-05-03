#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 200000

int N, C;
int num[MAX_N];

int getCount(int distance){
    int sum=1;
    int preIdx = 0;
    for (int i=1; i<N; i++) {
        if (num[i] - num[preIdx]>=distance){
            sum++;
            preIdx = i;
        }
    }
    return sum;
}

int main()
{
    scanf("%d %d\n", &N, &C);
    for (int i=0; i<N; i++){
        scanf("%d\n", &num[i]);
    }
    sort(num, num+N);


    int s = 1;
    int e = num[N-1];
    while ( s <= e) {
        int mid = (s+e)/2;
        if (getCount(mid) >= C) s = mid+1;
        else e = mid-1;
    }

    printf("%d\n", e);

    return 0;
}

