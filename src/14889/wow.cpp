#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }
inline int abs(int x) { return x < 0 ? -x : x; }

int N;
int map[20][20];
int ans = 0x3f3f3f3f;

void solve(int a, int b, int st1, int st2, int info1, int info2, int pivot) {
    printf("solve : a:%d b:%d, info1:0x%x, info2:0x%x pivot=%d\n", a, b, info1, info2, pivot);
	if (a + b == N) {
		ans = min(ans, abs(st1 - st2));
		return;
	}

	int plus = 0;
	if (a < N / 2) {
		for (int m = 0;m < N;m++) {
			if (info1 & (1 << m)) 
                plus += (map[pivot][m] + map[m][pivot]);
		}
		solve(a + 1, b, st1 + plus, st2, (info1 | (1 << pivot)), info2, pivot + 1);
	}

	if (b < N / 2) {
		plus = 0;
		for (int m = 0;m < N;m++) {
			if (info2 & (1 << m)) plus += (map[pivot][m] + map[m][pivot]);
		}
		solve(a, b + 1, st1, st2 + plus, info1, (info2 | (1 << pivot)), pivot + 1);
	}
}

int main() {

	scanf("%d", &N);
	for (int n = 0;n < N;n++)
        for (int m = 0;m < N;m++) 
            scanf("%d", &map[n][m]);
	solve(0, 0, 0, 0, 0, 0, 0);
	printf("%d\n", ans);

	return 0;
}

