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