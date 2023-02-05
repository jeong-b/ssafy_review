// 문제이해
//  N * N 크기의 카페 (20*20)
// 1 ~ 100사이의 디저트 종류
// 가장 많은 카페를 들리는 루트에서 카페의 수를 찾는 것 | 최대 -> 가지치기 불가능
// 중복 X, 한 칸만 X, 출발점으로 돌아와야함
// 이동 룰 만들기 우하 -> 좌하 -> 좌상 -> 우상

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
using namespace std;

int N, cnt, ans = -1;
int map[20][20];
int used[20][20];
int dat[101];
int dir[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

void dfs(int y, int x, int dirN, int dy, int dx)
{
	// 2. 기저 조건 : 다시 시작 자리에 도착할 때
	if (y == dy && x == dx)
	{
		if (cnt > ans) ans = cnt;
		return;
	}

	// 4. 가지치기
	// #1. 벽 (범위확인) -> 방향배열은 필수
	if (y < 0 || y >= N || x < 0 || x >= N) return;
	// #2. 중복 방문 확인  -> used
	if (used[y][x] == 1) return;
	// #3. 같은 종류 카페 확인 -> dat
	if (dat[map[y][x]] == 1) return;

	// 3. 기록 및 처리
	used[y][x] = 1;
	dat[map[y][x]] = 1;
	cnt++;

	// 1. 재귀 기본 구조
	// #1. 진쟁방향 유지
	dfs(y + dir[dirN][0], x + dir[dirN][1], dirN, dy, dx);

	// #2. 진행방향 변경
	if (dirN < 3)
	{
		dirN++;
		dfs(y + dir[dirN][0], x + dir[dirN][1], dirN, dy, dx);
		dirN--;
	}

	// 5. 복구
	used[y][x] = 0;
	dat[map[y][x]] = 0;
	cnt--;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);

	int T, test_case;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// reset
		memset(map, 0, sizeof(map));
		memset(used, 0, sizeof(used));
		memset(dat, 0, sizeof(dat));
		ans = -1;
		cnt = 0;

		// input
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		// solve -> 모든 위지를 출발점으로 두고 dfs 탐색
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				used[i][j] = 1;
				dat[map[i][j]] = 1;
				cnt++;

				//dfs(다음 y, 다음 x, 방향, 도착 y, 도착 x) 
				dfs(i + 1, j + 1, 0, i, j);
				
				used[i][j] = 0;
				dat[map[i][j]] = 0;
				cnt--;
			}
		}

		// output
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}