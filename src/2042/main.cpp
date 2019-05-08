#include <stdio.h>
#define MAX_N 1000001

int N,M,K;
int arr[MAX_N];

class BIT {
    long long data[MAX_N];
    int length;

public:
    BIT() : length(0) {}

    void init(int arr[], int size){
        length = size;
        for (int i=1; i<=length; i++) {
            update(i, arr[i]);
        }
    }

    void update(int i, int num) {
        while (i<=length) {
            data[i] += (long long)num;
            i += (i&-i);
        }
    }

    long long sum(int i) {
        long long sum = 0L;
        while (i>0) {
            sum += (long long)data[i];
            i -= (i&-i);
        }
        return sum;
    }
};

BIT bit;

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i=1; i<=N; ++i) {
        scanf("%d\n", &arr[i]);
    }
    bit.init(arr, N);
    int cnt=M+K;
    while (cnt--) {
        int q, x, y; scanf("%d %d %d\n", &q, &x, &y);
        if (q==1) {
            int diff = y - arr[x];
            arr[x] = y;
            bit.update(x, diff);
        } else if (q==2) {
            long long a1 = bit.sum(x-1);
            long long a2 = bit.sum(y);
            printf("%lld\n", a2-a1);
        }
    }

    return 0;
}
