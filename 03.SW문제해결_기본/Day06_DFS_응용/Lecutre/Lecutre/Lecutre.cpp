/*
#include <iostream>
using namespace std;

int vect[5][5] = {
	0, 1, 0, 0, 0,
	0, 0, 1, 1, 0,
	0, 0, 0, 1, 1,
	0, 0, 0, 0, 0,
	0, 0, 0, 1, 0
};
int arr[5] = { 9, 8, 15, 22, 4 };

int main()
{
	int maxIndex = 0, maxValue = 0;
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += vect[j][i];
		}
		if (sum > maxValue)
		{
			maxValue = sum;
			maxIndex = i;
		}
	}
	cout << arr[maxIndex];

	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int vect[4][4] = {
	0, 1, 0, 1,
	0, 0, 0, 1,
	1, 0, 0, 1,
	0, 0, 0, 0,
};
int arr[4] = { 15, 99, 88, -77 };
int nodeIndex;

int main()
{
	cin >> nodeIndex;
	for (int i = 0; i < 4; i++)
	{
		if (vect[nodeIndex][i] == 1)
		{
			cout << arr[i] << " ";
		}
	}

	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int map[6][6] = {
	0, 1, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 0,
	0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0
};
char name[6] = { 'A', 'B', 'T', 'R', 'V', 'G' };
char path[3];

void dfs(int now, int level)
{	
	if (level == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		if (map[now][i] == 0) continue;	
		path[level] = name[i];
		dfs(i, level + 1);
		path[level] = 0;
	}
}

int main()
{
	path[0] = name[0];
	dfs(0, 1);

	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];

void dfs(int now)
{
	cout << now;
	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] >= 1) continue;
		used[i] = 1;
		dfs(i);
		// used[i] = 0; 을 사용하지 않으면 연결된 Node를 한번씩만 탐색한다.
		// used[i] = 1; 을 사용하면 모든 경로를 탐색한다.
		used[i] = 0;
	}
}

int main()
{
	used[0] = 1;
	dfs(0);
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];
int flag;

void dfs(int now, int finish)
{
	if (now == finish)
	{
		flag = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1) continue;
		if (flag == 1) continue;

		used[i] = 1;
		
		dfs(i, finish);
	}
}

int main()
{
	dfs(0, 3);
	if (flag == 1) cout << "O";
	else cout << "X";
	
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];
int cnt = 0;

void dfs(int now, int finish)
{
	if (now == finish)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;

		dfs(i, finish);

		used[i] = 0;
	}
}

int main()
{
	used[0] = 1;
	dfs(0, 3);
	cout << cnt;

	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 50, 60, 300,
	0, 0, 7, 0,
	30, 0, 0, 10,
	0, 0, 0, 0
};
int used[4];
int minValue = 21e8;

void dfs(int now, int sum)
{
	if (now == 3)
	{
		if (sum < minValue) minValue = sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;
		dfs(i, sum + map[now][i]);
		used[i] = 0;
	}

}

int main()
{
	used[0] = 1;
	dfs(0, 0);
	cout << minValue;

	return 0;
}
*/

/*
*/
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr(5); 
int node;

void run(int now)
{
	cout << now;

	for (int i = 0; i < arr[now].size(); i++)
	{
		run(arr[now][i]);
	}

}

int main()
{
	//arr.push_back({});
	//arr.push_back({});
	//arr.push_back({});
	//arr.push_back({});
	//arr.push_back({});
	
	arr[0] = { 3 };
	arr[1] = { 2, 0 };
	arr[3] = { 4, 2 };
	arr[4] = { 2 };

	//for (int i = 0; i < arr.size(); i++)
	//{
	//	for (int j = 0; j < arr[i].size(); j++)
	//	{
	//		cout << arr[i][j];
	//	}
	//	cout << "\n";
	//}
	cin >> node;

	for (int i = 0; i < arr[node].size(); i++)
	{
		cout << arr[node][i];
	}

	return 0;
}