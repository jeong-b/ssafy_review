#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
using namespace std;

int D, W, K;
int injectionCnt = 0;
int ans = 21e8;
int film[13][20];
int filmCopy[13][20];

bool test()
{
	for (int i = 0; i < W; i++)
	{
		int base = filmCopy[0][i];
		int cnt = 0;
		int flag = 0;
		for (int j = 0; j < D; j++)
		{
			if (filmCopy[j][i] == base)
			{
				cnt++;
				if (cnt == K)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				base = filmCopy[j][i];
				cnt = 1;
			}
		}
		if (flag == 0) return false;
	}
	return true;
}

void run(int level)
{
	// 2. 기저 조건
	if (level == D)
	{
		// 성능테스트
		if (test() == true)
		{
			if (injectionCnt < ans) ans = injectionCnt;			
		}
		return;
	}

	// #1. 아무것도 안한다
	// 4. 가지 치기
	if (injectionCnt > ans) return;

	// 3. 기록 및 처리

	// 1. 재귀 구성
	run(level + 1);

	// 5. 복구


	// #2. A로 바꾼다
	// 4. 가지 치기
	if (injectionCnt > ans) return;

	// 3. 기록 및 처리
	for (int i = 0; i < W; i++)
	{
		filmCopy[level][i] = 0;
	}
	injectionCnt++;

	// 1. 재귀 구성
	run(level + 1);

	// 5. 복구
	for (int i = 0; i < W; i++)
	{
		filmCopy[level][i] = film[level][i];
	}
	injectionCnt--;


	// #3. B로 바꾼다
	// 4. 가지 치기
	if (injectionCnt > ans) return;

	// 3. 기록 및 처리
	for (int i = 0; i < W; i++)
	{
		filmCopy[level][i] = 1;
	}
	injectionCnt++;

	// 1. 재귀 구성
	run(level + 1);

	// 5. 복구
	for (int i = 0; i < W; i++)
	{
		filmCopy[level][i] = film[level][i];
	}
	injectionCnt--;


}

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);

	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		// reset
		// 첫번째 tc는 답나오는데 뒤에 안나온다, 중간것을 따로 넣으면 잘 나온다 : 100% reset 문제
		injectionCnt = 0;
		ans = 21e8;
		memset(film, 0, sizeof(film));
		memset(filmCopy, 0, sizeof(filmCopy));		

		// input
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> film[i][j];
				filmCopy[i][j] = film[i][j];
			}
		}

		// solve
		if (test()) ans = 0;
		else run(0);

		// output
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}