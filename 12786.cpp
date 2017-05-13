#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, m, tmp;
const int INF = 987654321;
int dp[101][21];
vector<vector<int>> a;
int solution(int curpos, int height) {
	if (curpos >= n)	return 0;
	int& ret = dp[curpos][height];
	if (ret != -1)	return ret;
	ret = INF;
	for (int i = 0; i < a[curpos].size(); i++) {
		int nextheight = a[curpos][i];
		if (abs(nextheight - height) <= 1)
			ret = min(ret, solution(curpos + 1, nextheight));
		else if (nextheight == 2 * height)
			ret = min(ret, solution(curpos + 1, nextheight));
		else if (height > 10 && nextheight == 20)
			ret = min(ret, solution(curpos + 1, nextheight));
		else
			ret = min(ret, solution(curpos + 1, nextheight) + 1);
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
	a.resize(n+1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			a[i].push_back(tmp);
		}
	}
	int ans = solution(0, 1);
	printf("%d\n", ans > k ? -1 : ans);
}