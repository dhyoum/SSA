/* 5719 
 * https://www.acmicpc.net/problem/5719
 */
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 502
#define INF 987654321

using namespace std;

int N, M;
int S, E;
struct Edge {
    int d, v;
    bool operator< (const Edge& rhs) const {
        return rhs.d < d || (!(d < rhs.d) && (rhs.v < v));
    }
};
int G[MAX_N][MAX_N];
int dist[MAX_N];
int path[MAX_N];

void dijkstra(int s) {
    printf("dijkstra\n");
    for (int i=0; i<N; i++) {
        dist[i] = INF;
    }
    // dist[s] = 0;
    priority_queue<Edge> q;
    q.push({0, s});
    while (!q.empty()) {
        int curr = q.top().v;
        int distance = q.top().d;
        // printf("pop : curr:%d, distance:%d\n", curr, distance);
        q.pop();

        if (dist[curr] <= distance)  {
          //  printf("dist[%d]:%d : continue\n", curr, dist[curr]);
            continue;
        }
        dist[curr] = distance;
        for (int next=0; next < N; next++) {
            if ( G[curr][next] == INF ) continue;
            int cost = G[curr][next];
            if (dist[next] == INF) {
                printf("c:%d, n:%d\n", curr, next);
                // dist[next] = distance + cost;
                // printf("dist[%d]:%d,  %d->%d: %d\n", next, dist[next], curr, next, cost);
                q.push({distance + cost, next});
            }
        }
    }
}

void removeEdge(int e) {
    queue<int> q; q.push(e);
    printf("remove\n");
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for(int i=0;i <N; i++) {
            if (dist[v] == dist[i] + G[i][v] && G[i][v] != INF) {
                printf("%d->%d : %d\n", i, v, G[i][v]);
                G[i][v] = INF;
                q.push(i);
            }
        }
    }
}

int main()
{
    while (1) {
        scanf("%d %d\n", &N, &M);
        if (N==0 && M==0) break;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                G[i][j] = INF;
            }
        }
        scanf("%d %d\n", &S, &E);
        for (int i=0; i<M; i++) {
            int u, v, p;
            scanf("%d %d %d\n", &u, &v, &p);
            G[u][v] = p;
        }
        dijkstra(S);
        printf("%d\n", dist[E]==INF?-1:dist[E]);
        removeEdge(E);
        // dijkstra(S);
        // printf("%d\n", dist[E]==INF?-1:dist[E]);
    }

    return 0;
}

