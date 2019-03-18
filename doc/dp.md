### fibonacci
```c
int f(int n)
{
	if (n <= 2)	return 1;
	return f(n - 1) + f(n - 2);
}
```
- 메모이제이션 ( 하향식 설계)
```c
int DT[100001];
int f(int n)
{
	if (n <= 2)	return 1;
	if (!DT[n]) DT[n] = f(n - 1) + f(n - 2);
	return DT[n];
}
```

### Combination

- D[N][K] N개 중에 K 개를 고르는 경우의 수 (하향식 설계)
```c
int DT[31][31];
int f(int n, int k)
{
	if (k == n) DT[n][k] = 1;
	else if (k == 1) DT[n][k] = n;
	else
	{
		if (!DT[n][k])
			DT[n][k] = f(n - 1, k - 1) + f(n - 1, k);
	}
	return DT[n][k];
}

for (int i = 1; i <= n; i++)
{
	for (int j = 1; j <= k && j <= i; j++)
	{
		if (i == j) DT[i][j] = 1;
		else if (j == 1) DT[i][j] = i;
		else DT[i][j] = DT[i - 1][j - 1] + DT[i - 1][j];
	}
}

```
### 백트랙킹 -> 완전 탐색
solve(n, k)는 현재까지 k 개의 물건을 고른 상태이며,
n 번째 물건에 대해서 고를지 안 고를지 결정하고자 하는 상태

- solve(n+1, k+1) : 이번 물건을 선택하고 다음 물건에 대해서 탐색을 진행
- solve(n+1, k)   : 이번 물건을 선택하지 않고, 다음 물건에 대해서 탐색을 진행


```c
void solve(int n, int k)
{
	if (k == K)
	{
		ans++;
		return;
	}
	if (n == N) return;
	solve(n + 1, k + 1);
	solve(n + 1, k);
}
```

##### 무엇이 다른가??
위처럼 수학적 공식에 기반한 점화식 설계가 아니라, 단순히 선택과 미선택으로 문제를 단순화시켜서 Loop 를 돌리고,
마찬가지로, 메모이제이션을 적용한다.
- 상향식 설계
```c
int N, K, DT[31][31];
int f(int n, int k)
{
	if (k == K) return 1;
	if (n == N) return 0;
	if (!DT[n][k])
		DT[n][k] = f(n + 1, k + 1) + f(n + 1, k);
	return DT[n][k];
}
```
