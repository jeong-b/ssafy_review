// BFS : 너비 우선 탐색
// 특정 노드부터 인접한 노드부터 탐색
// Queue : 먼저 들어간게 먼저 나오는 선입선출 구조, 공정한 자료구조
// BFS의 단계
// #1. Queue 준비 : Queue 생성 -> Queue에 시작 노드 삽입
// #2. BFS 동작 : 대기열의 맨 앞의 노드 방문 - now : 지금 내가 방문하고 있는 노드
// -> 내가 갈 수 있는 노드 판단 -> 대기열 삽입 -> 해당 동작을 더이상 갈 노드가 없을 때까지 반복
// queue 사용법
// #include <queue> : 헤더 생성
// queue<int> q; : queue 생성
// #1. 삽입
// q.push(1); : [ 1     ]
// q.push(2); : [ 1 2   ]
// q.push(3); : [ 1 2 3 ]
// #2. front() : 맨 앞의 값을 확인
// #3. size() : 요소의 개수
// #4. empty() : 비어있으면 true, 아니면 false
// #5. pop() : 맨앞의 요소를 삭제
// BFS 활용
// 최단 경로 : 특정 노드에서 특정노드까지 최단 경로를 구하기 용이
// DFS와 BFS의 시간복잡도
// #1. 일반적인 완전 탐색(V는 노드개수, E는 간선개수)
// -> 인접 행렬 : O(V^2) 
// -> 인접 리스트 : O(v + E)
// #2. DFS - backtracking
// 재귀의 시간 복잡도 : O(2^N) ~ O(N!)
//

/* BFS 연습 - 인접 행렬 활용
#include <iostream>
#include <queue>
using namespace std;

int nodeCnt, edgeCnt;
int map[10][10];

void bfs(int start)
{
	// 1. queue 준비
	queue<int> q;
	// queue에 시작 노드 삽입
	q.push(start);

	while (!q.empty())
	{
		// 2. queue의 맨 앞의 노드를 방문
		int now = q.front(); // now : 지금 방문하는 노드
		// queue에서 삭제
		q.pop();

		cout << now << " ";

		// 3. 갈 수 있는 노드를 판단하고 -> queue에 삽입
		for (int next = 0; next < nodeCnt; next++)
		{
			if (map[now][next] == 0) continue;
			q.push(next);
		}
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
	}

	bfs(0);

	return 0;
}
*/

/* BFS연습 - 입접 리스트 활용
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodeCnt, edgeCnt;
vector<vector<int>> map;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) map.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << " ";
		
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i];			
			q.push(next);
		}
	}
}

int main()
{
	input();

	bfs(0);

	return 0;
}
*/

/* BFS연습 - 양방향 연결, 중복 방지
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) map.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	int used[10];
	used[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i];

			if (used[next] == 1) continue;

			used[next] = 1;
			q.push(next);
		}
	}
}

int main()
{
	input();

	bfs(0);

	return 0;
}
*/

/* DFS와 비교
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int used[10];
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) map.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
}

void dfs(int now)
{
	cout << now << " ";
	for (int i = 0; i < map[now].size(); i++)
	{
		int to = map[now][i];

		if (used[to] == 1) continue;

		used[to] = 1;
		dfs(to);
	}
}

int main()
{
	input();

	used[0] = 1;
	dfs(0);

	return 0;
}
*/

/* BFS 활용 - used에 경로의 거리를 기록 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) map.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	int used[10] = { 0 };
	used[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i];

			if (used[next] != 0) continue;

			used[next] = used[now] + 1;
			q.push(next);
		}
	}

	cout << "\n";

	for (int i = 0; i < 4; i++)
	{
		cout << used[i] - 1 << " ";
	}
}

int main()
{
	input();

	bfs(0);	

	return 0;
}
*/

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