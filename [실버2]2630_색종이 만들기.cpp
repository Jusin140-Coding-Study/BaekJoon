#include <iostream>
#include <vector>
using namespace std;

int white = 0;
int blue = 0;
vector<vector<int>> vecPaper;
void Check(int start, int end , int N);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vecPaper = vector<vector<int>>(N, vector<int>(N, -1));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> vecPaper[i][j];

	Check(0, 0, N);

	cout << white << "\n" << blue << "\n";
	return 0;
}

void Check(int start, int end, int N)
{
	// 더이상 쪼개지지 않는 경우
	if (1 == N)
	{
		vecPaper[start][end] == 1 ? ++blue : ++white;
		return;
	}

	int startcolor = vecPaper[start][end];
	bool bCheck = false;

	for (int i = start; i < start + N; ++i)
	{
		for (int j = end; j < end + N; ++j)
		{
			if (vecPaper[i][j] != startcolor)
			{
				bCheck = true;
				break;
			}
		}
		if (bCheck) break;
	}

	if (bCheck)
	{
		Check(start, end, N / 2);
		Check(start + N / 2, end, N / 2);
		Check(start, end + N / 2, N / 2);
		Check(start + N / 2, end + N / 2, N / 2);
	}
	else
	{
		startcolor == 1 ? ++blue : ++white;
	}
}