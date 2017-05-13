#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;
int n, k;
int coin[101];
int dp[10001];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < 10001; i++)
		dp[i] = 987654321;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] >= 987654321)
		printf("-1\n");
	else
		printf("%d\n", dp[k]);
}