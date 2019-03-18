### 순환하는 외파원 문제
 - 대표적인 NP 문제로 풀이가 어렵다.
 - 노드가 20 이면, 경우의 수는 20! 완전탐색은 불가능
 - 그렇다면, 대부분의 완전탐색이 그렇듯, 메모이제이션을 통해서 속도를 높인다.
 
 ```c
int solve(int pos, int visit)
{
	int& ans = memo[pos][visit];
	if (ans != 987654321) return ans;

	if (visit == (1 << N) - 1 - 2)
		return ans = G[pos][1];

	for (int next = 2; next < N; next++) {
		if (!(visit & (1 << next)) && G[pos][next])	{
			int ret = G[pos][next] + solve(next, visit | (1 << next));
			if (ret < ans)	ans = ret;
		}
	}
	return ans;
}
```
