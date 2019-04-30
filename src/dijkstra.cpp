struct Edge {
    int cost, e;
    bool operator< (const Edge& rhs) const {
        return cost < rhs.cost || (!(rhs.cost < cost) && (e < rhs.e) ) ;
    }
};
vector<Edge> G[1001];
int dijkstra(int start, int end)
{
    int dist[1001];
    for (int i = 1; i <= 1000; ++i) {
        dist[i] = 987654321;
    }

    priority_queue<Edge> q;
    q.push({0, start});

    while (!q.empty()) {
        int current = q.top().e;
        int distance = q.top().cost;
        q.pop();
        if (dist[current] < distance) continue;

        for (int i = 0; i < (int)G[current].size(); i++)    {
            int next = G[current][i].e;
            if (dist[next] > G[current][i].cost + distance) {
                dist[next] = G[current][i].cost + distance;
                q.push({ dist[next], next});
            }
        }
    }
    return dist[end];
}
