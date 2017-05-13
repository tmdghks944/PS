#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int maxx = -1;
	int sum = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		maxx = max(maxx, tmp);
		sum += tmp;
	}
	printf("%d\n", sum - maxx);
}