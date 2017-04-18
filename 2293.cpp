#include <iostream>
#include <cstdio>

using namespace std;
int n, k;
int coin[101];
int dp[10001];
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[k]);
}