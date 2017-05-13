#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int s, e, n, m, u, v;
const int INF = 987654321;
vector<vector<pair<int, int>>> arr;

vector<int> solution(int s) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	dist[s] = 0;
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 0; i < arr[here].size(); i++) {
			int there = arr[here][i].first;
			int therecost = cost + arr[here][i].second;
			if (dist[there] > therecost) {
				dist[there] = therecost;
				pq.push({ -therecost,there });
			}
		}
	}
	return dist;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &s, &e);
	scanf("%d%d", &n, &m);
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		arr[u].push_back({v,1});
		arr[v].push_back({ u,1 });
	}
	vector<int> ans = solution(s);
	if (ans[e] == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans[e]);
	}
	return 0;
}