// Graph : Data간의 연결된 관계 - 재귀를 이용하여 각 Data 확인
// 각 Data는 특정 물체 또는 상황 - 강의실 입장 -> 아프면 조퇴, 안아프면 강의듣기
// 각 Data간 연결은 관계나 조건을 나타냄
// 각 Data는 정점, Node, Vertex, 관계는 간선, Edge라고 부른다.
// 사용 예시 :  역에서 이동하는 방법, 컴퓨터 간의 Data 이동, 길찾기, 레시피 등
// Edge의 정보를 저장하는 방법
// 1. 인접 행렬 : DAT확장, 2차 배열 사용 | adj[from][to] = from에서 to로 갈 수 있는가?
// 장점 : 특정 from에서 특정 to로 갈 수 있는지 판별하기 용이함 | 모든 from, to에 대한 정보가 전부 있음
// 단점 : 메모리 낭비가 심함, node개수의 제곱만큼 메모리를 필요로함
// 2. 인접 리스트 : vector 사용
// 장점 : 메모리 낭비가 없음, Edge의 개수만큼만 메모리를 필요로함
// 단점 : 특정 from에서 특정 to로 갈 수 있는지 판별하기 어려움
// 입력 예시
// Node개수, Edge개수 -> Edge 정보(from, to)

/* 1. 인접 행렬
#include <iostream>
using namespace std;

int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	int adj[6][6] = { 0 };

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	int node = 1; // from의로 사용할 위치

	for (int i = 1; i <= 5; i++)
	{
		if (adj[node][i] == 0) continue;
		cout << i << " "; // 갈 수 있는 to를 출력
	}

	return 0;
}
*/

/* 2. 인접 리스트
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	vector<int> v[6]; // vector<저장할 Data 자료형> v;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to); // vector.push_back(value) : vector 맨 뒤에 공간을 추가해서 value라는 값을 저장
	}

	int node = 1; // from의로 사용할 위치

	for (int i = 0; i < v[node].size(); i++) // vector.size() : vector가 갖고 있는 Data 개수
	{
		int to = v[node][i];
		cout << to << " "; // 갈 수 있는 to를 출력
	}

	return 0;
}
*/

/* Graph를 활용하는 재귀함수 - 인접 행렬 활용
#include <iostream>
using namespace std;

int nodeCnt, edgeCnt;
int adj[6][6];

void dfs(int now)
{
	// 2. 기저 조건(option) - 생략가능한 이유 : 가지치기를 통해 재귀를 시키지 않음

	for (int to = 1; to <= nodeCnt; to++)
	{
		// 4. 가지치기
		if (adj[now][to] == 0) continue; // now -> to 로 갈 수 없으면 무시
		
		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		
		// 1. 재귀 기존 구조
		dfs(to);
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	dfs(1);

	return 0;
}
*/

/* Graph를 활용하는 재귀함수 - 인접 리스트 활용
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[6];

void dfs(int now)
{
	for (int i = 0; i < v[now].size(); i++)
	{
		int to = v[now][i];
		cout << now << "에서 " << to << "로 갑니다!\n";
		dfs(to);
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	dfs(1);

	return 0;
}
*/

/* 문제해결 - Edge가 순환구조일때 무한재귀가 도는 것을 해결
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[6];
int used[6];

void dfs(int now)
{
	// 2. 기져 조건

	for (int i = 0; i < v[now].size(); i++)
	{
		// now -> to 찾기
		int to = v[now][i];
		
		// 4. 가지치기
		if (used[to] == 1) continue;
		
		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		used[to] = 1;
		
		// 1. 재귀 기본  구조
		dfs(to);		
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	used[1] = 1;
	dfs(1);

	return 0;
}
*/

/* 문제해결 - 경로 저장
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[6];
vector<int> path;
int used[6];

void dfs(int now)
{
	// 2. 기져 조건
	if (now == 5)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
	{
		// now -> to 찾기
		int to = v[now][i];

		// 4. 가지치기
		if (used[to] == 1) continue;

		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		used[to] = 1;
		path.push_back(to);

		// 1. 재귀 기본  구조
		dfs(to);

		// 5. 복구
		path.pop_back();
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	path.push_back(1);
	used[1] = 1;
	dfs(1);

	return 0;
}
*/

/* 문제해결 - 경우의 수
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[7];
vector<int> path;
int used[8];
int cnt;

void dfs(int now)
{
	// 2. 기져 조건
	if (now == 7)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
	{
		// now -> to 찾기
		int to = v[now][i];

		// 4. 가지치기
		if (used[to] == 1) continue;

		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		used[to] = 1;
		path.push_back(to);

		// 1. 재귀 기본  구조
		dfs(to);

		// 5. 복구
		path.pop_back();
		used[to] = 0;
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	path.push_back(1);
	used[1] = 1;
	dfs(1);

	cout << "경로의 수 : " << cnt << "\n";

	return 0;
}
*/