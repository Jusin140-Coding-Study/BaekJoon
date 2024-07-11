#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int M(0);
	cin >> N >> M;

	// N x N 정수 행렬 초기화
	vector<vector<int>> P(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> S(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> P[j][i];

			S[j][i] = S[j][i - 1] + S[j - 1][i] - S[j - 1][i - 1] + P[j][i];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int x1(0); int y1(0);
		int x2(0); int y2(0);

		cin >> x1 >> y1 >> x2 >> y2;

		int Result = S[y2][x2] - S[y1 - 1][x2] - S[y2][x1 - 1] + S[y1 - 1][x1 - 1];
		cout << Result << "\n";
	}
}