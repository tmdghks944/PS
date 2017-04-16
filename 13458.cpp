#include <iostream>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;
ll arr[1000001];
ll n, b, c;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= b) {
			ans++;
		}
		else {
			if ((arr[i] - b) % c == 0) {
				ans += 1 + (ll)((arr[i] - b) / c);
			}
			else {
				ans += 2 + (ll)((arr[i] - b) / c);
			}
		}
	}
	cout << ans << endl;
	return 0;
}