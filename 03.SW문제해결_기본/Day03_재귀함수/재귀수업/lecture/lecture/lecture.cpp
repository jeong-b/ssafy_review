/*
#include <iostream>
using namespace std;

int vect[4][4] = {
	3, 1, 4, 2,
	1, 1, -1, 1,
	2, 3, 1, 4,
	5, 1, 0, 3,
};
int maxValue = -21e8;
int minValue = 21e8;

void run(int level, int gop)
{
	if (level == 4) 
	{
		if (maxValue < gop) maxValue = gop;
		if (minValue > gop) minValue = gop;
		//cout << gop << "\n";
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		run(level + 1, gop * vect[level][i]);
	}
}

int main()
{
	run(0, 1);
	cout << maxValue << "\n";
	cout << minValue;

	return 0;
}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;

char name[10];// = "BTSGOOD";
char path[3];

void run(int level, int len)
{
	if (level == 3)
	{
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < len; i++)
	{
		path[level] = name[i];
		run(level + 1, len);
	}
}

int main()
{
	cin >> name;
	int len = strlen(name);
	run(0, len);

	return 0;
}
*/
/*
#include <iostream>
using namespace std;

char path[10];
int used[7];

void run(int level)
{
	if (level == 3)
	{
		cout << path << endl;
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		if (used[i] == 1) { continue; }

		used[i] = 1;
		path[level] = i + '0';

		run(level + 1);

		path[level] = 0;
		used[i] = 0;
	}
}

int main()
{
	run(0);
	return 0;
}
*/
/*
#include <iostream>
using namespace std;

char card[5] = { 'A', 'G', 'K', 'R', 'P' };
char path[4];
int used[256];

void run(int level)
{
	if (level == 4)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		if (used[card[i]] == 1) { continue; }

		used[card[i]] = 1;
		path[level] = card[i];

		run(level + 1);

		path[level] = 0;
		used[card[i]] = 0;
	}
}

int main()
{
	run(0);
	return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 6; i++)
	{
		for (int j = i; j <= 6; j++)
		{
			cout << i << j << "\n";
		}
	}

	return 0;
}
*/
/*
#include <iostream>
using namespace std;

char path[2];

void run(int level, int start)
{
	if (level == 2)
	{
		cout << path << "\n";
		return;
	}

	for (int i = start; i <= 6; i++)
	{
		path[level] = i + '0';
		run(level + 1, i);
		path[level] = 0;
	}
}

int main()
{
	run(0, 1);

	return 0;
}
*/
// 주사위 3개로 나오는 눈금  1.중복순열, 2.순열(중복X) 3.조합(중복X)
/*
#include <iostream>
using namespace std;

char path[3];

void run(int level)
{
	if (level == 3)
	{
		cout << path << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		path[level] = i + '0';
		run(level + 1);
		path[level] = 0;
	}
}

int main()
{
	run(0);
	return 0;
}
*/

#include <iostream>
using namespace std;

char path[3];
int used[7];

void run(int level)
{
	if (level == 3)
	{
		cout << path << "\n";
		return;
	}
	for (int i = 1; i <= 6; i++)
	{
		if (used[i] == 1) { continue; }

		path[level] = i + '0';
		used[i] = 1;

		run(level + 1);

		path[level] = 0;
		used[i] = 0;
	}
}

int main()
{
	run(0);
	return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{

	return 0;
}
*/