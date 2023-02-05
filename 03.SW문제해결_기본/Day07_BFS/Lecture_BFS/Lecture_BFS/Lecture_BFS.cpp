/* BFS 응용 -  가중리스트와 구조체 활용
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int nodeIndex;
	int price;
};

vector<vector<Node>> alist;
vector<int> path;
int used[4];
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) alist.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, price;
		cin >> from >> to >> price;
		Node info;
		info.nodeIndex = to;
		info.price = price;
		alist[from].push_back(info);
	}
}

void dfs(int now, int sum)
{
	if (now == 3)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << sum <<  "\n";
		return;
	}

	for (int i = 0; i < alist[now].size(); i++)
	{
		Node next = alist[now][i];

		if (used[next.nodeIndex] == 1) continue;

		used[next.nodeIndex] = 1;
		path.push_back(next.nodeIndex);

		dfs(next.nodeIndex, sum + next.price);

		used[next.nodeIndex] = 0;
		path.pop_back();
	}
}

int main()
{
	input();
	used[0] = 1;
	path.push_back(0);
	dfs(0, 0);

	return 0;
}
*/

/* BFS - Tree 구조(인접행렬)
#include <iostream>
#include <queue>
using namespace std;

int adj[5][5] = {
	0, 1, 0, 0, 1,
	0, 0, 1, 1, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0
};
char name[5] = { 'A', 'C', 'T', 'S', 'B' };
queue<int> q;

int main()
{
	q.push(0);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << name[now];

		for (int i = 0; i < 5; i++)
		{
			if (adj[now][i] == 0) continue;
			q.push(i);
		}
	}

	return 0;
}
*/

/* mission - BFS - Tree 구조(인접리스트)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> alist;
queue<int> q;
char name[5] = { 'A', 'C', 'T', 'S', 'B' };
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) alist.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
	}
}


int main()
{
	input();

	q.push(0);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << name[now];

		for (int i = 0; i < alist[now].size(); i++) q.push(alist[now][i]);		
	}

	return 0;
}
*/

/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int n;
	int lev;
};

vector<vector<int>> alist(5);
int used[5];
queue<Node> q;

int main() {

	alist[0] = { 1, 2, 3 };
	alist[1] = { 2, 3 };
	alist[2] = { 3 };
	alist[3] = { 4 };

	q.push({ 0, 0 });
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.n == 4) {
			cout << now.lev;
			break;
		}

		for (int i = 0; i < alist[now.n].size(); i++) {
			int next = alist[now.n][i];
			if (used[next]) continue;
			used[next] = 1;
			q.push({next, now.lev + 1});
		}
	}

	return 0;
}
*/

/* Flood Fill 예습
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[3][3];
struct Node {
	int y, x;
};
queue<Node> q;
int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, 1, -1 };

int main() {

	arr[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		//다음 갈수있는곳을 큐에 등록
		for (int t = 0; t < 4; t++) {
			int ny = now.y + directY[t];
			int nx = now.x + directX[t];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (arr[ny][nx] != 0) continue;

			arr[ny][nx] = arr[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}

	return 0;
}
*/