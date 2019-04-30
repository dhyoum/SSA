/* 2167
 * https://www.acmicpc.net/problem/2167
 */
#include <stdio.h>
#define MAX_N 10000

int N, M, K;
int dp[MAX_N][MAX_N];
int main()
{
    scanf("%d %d\n", &N, &M);
    for (int i=1;i <=N; ++i){
        for (int j=1; j<=M; ++j) {
            int v; scanf("%d ", &v);
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+v;
        }
    }

    scanf("%d\n", &K);
    for (int i=0; i<K; i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d\n", &y1, &x1, &y2, &x2);
    }

    for (int i=1;i <=N; ++i){
        for (int j=1; j<=M; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}

