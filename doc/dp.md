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

* solve(n+1, k+1) : 이번 물건을 선택(+1 즉 counting) 하고 다음 물건에 대해서 탐색을 진행
* solve(n+1, k)   : 이번 물건을 선택하지 않고, 다음 물건에 대해서 탐색을 진행


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

### 0/1 Knapsack 
선택, 미선택의 문제이므로, 모든 경우의 수 : 2^N 즉, 부분 집합(powerset)의 문제임.
완전탐색은 불가능 : 메모이제이션 어떻게? 

* DT[i][r] = i 번째 물건까지 고려했을 때, 배낭무게 r인 가치의 최대 합 
 - f(i + 1, r) : i 번째 물건을 선택하지 않아 배낭의 무게가 줄어들지 않음.
 - f(i + 1, r - w[i]) + v[i] : i번째 물건을 선택하여, 배낭의 무게가 줄어들고, 가치가 합산됨.
```c
int f(int i, int r)
{
	if (DT[i][r] != -1) return DT[i][r];
	if (i == n + 1) return DT[i][r] = 0;
	else if (r < w[i]) return DT[i][r] = f(i + 1, r);
	else return DT[i][r] = max(f(i + 1, r), f(i + 1, r - w[i]) + v[i]);
}
```

### 거스름돈

- 완전 탐색
```c
int m, n, coin[MAX], ans = 987654321;
void solve(int money, int cnt)
{
    if (money > m) return;
    if (money == m) ans = min(ans, cnt);

    for(int i=0; i<n; i++)
        solve(money+coin[i], cnt+1);
}
```
- 완전탐색버전을 함수 return 방식으로
```c
int f(int money)
{
    if (money == m) return 0;

    int res = 987654321;
    for(int i=0; i<n; i++) {
        if (money + coin[i]<=m)
            res = min(res, f(money+coin[i])+1);
    }
    return res;
}
```
- 메모이제이션
```c
int dp[10001];
int f2(int money)
{
    if (money == m) return dp[money]=0;

    if (dp[money]) return dp[money];

    dp[money] = 987654321;
    for(int i=0; i<n; i++) {
        if (money + coin[i]<=m)
            dp[money] = min(dp[money], f(money+coin[i])+1);
    }
    return dp[money];
}
```

### 메모이제이션 구현 패턴

1. 기저 사례를 먼저 처리 ( 입력이 범위를 벗어난 경우 )
2. 함수의 반환값을 확인하여, cache[] 의 초기값을 설정하여, 저장 여부 판단.
3. ref 형식으로 사용
```c
int& ref = cached[n][visit];
```
4. 다음 testcase 를 위한 초기화 수행
