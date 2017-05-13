#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int dp[1001][1001];
const int MOD = 1000000007;
int solution(int x, int y) {
	if (x == n - 1 && y == m - 1)
		return 1;
	else if (x >= n || y >= m)
		return 0;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 0;
	ret = (ret + solution(x + 1, y)) % MOD;
	ret = (ret + solution(x, y + 1)) % MOD;
	ret = (ret + solution(x + 1, y + 1)) % MOD;
	return ret;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	printf("%d\n", solution(0, 0));
}