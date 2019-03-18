### 순환하는 외파원 문제
 - 대표적인 NP 문제로 풀이가 어렵다.
 - 노드가 20 이면, 경우의 수는 20! 완전탐색은 불가능하다.
 - 그렇다면, 대부분의 완전탐색이 그렇듯, 메모이제이션을 통해서 속도를 높인다.
 - 중간중간에 가지치기도 할 수 있으면 좋다. 아래 코드에서는 없지만,
 - 이것은 20 개의 숫자를 나열하는 순열과 동일하고, 계산이 반복되므로 저장해서 재활용.
  
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
