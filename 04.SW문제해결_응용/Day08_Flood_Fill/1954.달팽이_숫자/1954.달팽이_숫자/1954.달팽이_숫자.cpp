#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
		int snail[10][10] = { 0 };
		int number, cnt = 1, y = 0, x = 0, i = 0;

		cin >> number;

		snail[0][0] = 1;
		while (cnt < (number * number))
		{
			y = y + dir[i][0];
			x = x + dir[i][1];
			
			if (y < 0 || y >= number || x < 0 || x >= number || snail[y][x] != 0)
			{
				y = y - dir[i][0];
				x = x - dir[i][1];
				i++;
				i = i % 4;
				continue;
			}			

			cnt++;
			snail[y][x] = cnt;
		}

		cout << "#" << testCase << "\n";

		for (int i = 0; i < number; i++)
		{
			for (int j = 0; j < number; j++)
			{
				cout << snail[i][j] << " ";
			}
			cout << "\n";
		}
		
		
	}

	return 0;
}