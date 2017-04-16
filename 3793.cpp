#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>

using namespace std;
int dp[1001][1001];
string str1, str2;
int size1, size2;
int solution(int pos1, int pos2)
{
	if (pos1 == size1 || pos2 == size2)
		return 0;
	int& ret = dp[pos1][pos2];
	if (ret != -1)return ret;
	ret = 0;
	if (str1[pos1] == str2[pos2])
		ret = max(ret, solution(pos1 + 1, pos2 + 1) + 1);
	else
		ret = max(ret, max(solution(pos1 + 1, pos2), solution(pos1, pos2 + 1)));
	return ret;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> str1 >> str2)
	{
		memset(dp, -1, sizeof(dp));
		size1 = str1.size();
		size2 = str2.size();
		printf("%d\n", solution(0, 0));
	}
}