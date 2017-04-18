#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;
int n, k;
int coin[101];
int dp[10000];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < 10000; i++)
		dp[i] = INT_MAX;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	printf("%d\n", dp[k]==INT_MAX ? -1 : dp[k]);
}