### 공통 조상 찾기

1. 각 노드의 Parent 정보를 모두 구성한다.
2. 각 노드를 전부 순회하여 (재귀적으로 구현), 각 노드의 Depth 와 Size 를 구한다.
3. 두 개의 노드를 비교하여, 높이가 같은 부분을 찾고, 같은 부분부터, 하나씩 줄여가면서 부모를 찾는다.

```c
int lca(int n1, int n2)
{
	int u = depth[n1] < depth[n2] ? n2 : n1;
	int v = depth[n1] < depth[n2] ? n1 : n2;

	int diff = depth[u] - depth[v];
	for (int k = 0; k < diff; k++)
	{
		u = parent[u];
	}

	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}
	return u;
}
```

### 좀더 빠른 방법은 ??
