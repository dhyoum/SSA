#include <stdio.h>
#include <string.h>

int dp[100][100];

inline int max(int a, int b) { return a < b ? b : a; }
int lcs(char* s1, char* s2)
{
	int n = strlen(s1);

	for (int i = 0; i < n; i++) {
		if (s1[0] == s2[i]) dp[0][i] = 1;
		else if (s1[i] == s2[0]) dp[i][0] = 1;
		else
			dp[i][i] = 0;
	}

	for (int i = 1; i < n; i++)	{
		for (int j = 1; j < n; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n - 1][n - 1];
}

int main()
{
	char str1[] = "abc";
	char str2[] = "abc";
	printf("lcs = %d\n", lcs(str1, str2));

	return 0;
}
