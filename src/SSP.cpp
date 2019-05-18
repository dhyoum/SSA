struct pii { 
	int cost, v;
	bool operator< (const pii& rhs) const {
		return cost > rhs.cost;
	}
};

vector<pii> adj[MAX_N];
int dist[MAX_N];

void dijkstra(int s) {
	for (int i = 0; i < N; i++) dist[i] = INF;
	dist[s] = 0;

	priority_queue<pii> q;
	q.push({0, s});
	while (!q.empty()) {
		int cost = q.top().cost;
		int v = q.top().v;
		q.pop();

		if (cost > dist[v]) continue;
		for (auto next : adj[v]) {
			if (dist[next.v] > cost + next.cost)	{
				dist[next.v] = cost + next.cost;
				q.push({ dist[next.v], next.v });
			}
		}
	}
}

void BellManFord(int s) {
	for (int i = 0; i < N; i++) dist[i] = INF;
	dist[s] = 0;
    
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (auto next : adj[j]) {
				if (dist[j] == INF) continue;
				if (dist[next.v] > dist[j] + next.cost) {
					dist[next.v] = dist[j] + next.cost;
				}
			}
		}
	}
}
