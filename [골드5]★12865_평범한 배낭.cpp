#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> DP;
vector<int> w;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N : ���� ����, K : �ؼ��� ��ƿ �� �ִ� ����
	int N, K;
	cin >> N >> K;

	w = vector<int>(N + 1);
	v = vector<int>(N + 1);

	// DP[i][j] : i�� ���� ������ ����� ���, ���� �� �ִ� �賶�� ���԰� j�� ���� �ִ� ��밪
	DP = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= N; ++i)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			// i��° ������ ���� �� �ִ� ������ ���
			// 1. ������ ���� �ʴ� ���, ���� ���Ǳ��� ����� ����� �ִ� ��밪�� ����
			// 2. ������ ����� ��, �� ������ ���Ը� �� ���Կ����� �ִ� ��밪�� ������ ���Ը� ���� ��
			if (j >= w[i])
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K];

	return 0;
}