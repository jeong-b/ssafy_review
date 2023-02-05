// 가중치 그래프는 간선의 값이 0이 아닐 때 반드시 1이 아닌 값

#include <iostream>
#include <vector>
using namespace std;

int nodeCount = 4, edgeCount = 6, sum = 0;
// 인접행렬 map[nodeCount][nodeCount] = {하드코딩}
int map[4][4] = {
	0, 7, 20, 8,
	0, 0, 5, 0,
	15, 0, 0, 0,
	0, 0, 6, 0
};
int used[4] = { 0 };

void dfs(int now, int sum)
{
	if (now == 2)
	{
		cout << sum << "\n";
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1)continue;
		used[i] = 1;
		dfs(i, sum + map[now][i]);
		used[i] = 0;
	}
}

int main()
{
	used[0] = 1;
	dfs(0, sum);

	return 0;
}