/*
* @title    : 1018번 체스판 다시 칠하기(실버4)
* @content  : 브루트 포스
* @author   : 손동찬
* @date     : 240710
* @time     : 4 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<char>> v(N, vector<char>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<char>> vCase1(8, vector<char>(8));
	vector<vector<char>> vCase2(8, vector<char>(8));

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (i & 1)
			{
				if (j & 1)
				{
					vCase1[i][j] = 'B';
					vCase2[i][j] = 'W';
				}
				else
				{
					vCase1[i][j] = 'W';
					vCase2[i][j] = 'B';
				}
			}
			else
			{
				if (j & 1)
				{
					vCase1[i][j] = 'W';
					vCase2[i][j] = 'B';
				}
				else
				{
					vCase1[i][j] = 'B';
					vCase2[i][j] = 'W';
				}
			}
		}
	}
	int Result = 64;

	for (int i = 0; i < N-7; ++i)
	{
		for (int j = 0; j < M-7; ++j)
		{
			int iCase1 = 0;
			int iCase2 = 0;

			for (int x = 0 ; x < 8 ; ++x)
			{
				for (int y = 0; y < 8 ; ++y)
				{
					if (vCase1[x][y] != v[x + i][y + j]) iCase1++;
					if (vCase2[x][y] != v[x + i][y + j]) iCase2++;
				}
			}

			Result = min(Result, iCase1);
			Result = min(Result, iCase2);
		}
	}

	cout << Result << "\n";

	return 0;
}