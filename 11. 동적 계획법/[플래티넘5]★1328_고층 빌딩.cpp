#include <iostream>
#include <vector>
using namespace std;

static long long mod = 100'000'000'7;
static long long D[101][101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int L = 0; int R = 0;
	cin >> N >> L >> R;

	// 건물이 1개인 경우의 수는 한개밖에 없음
	D[1][1][1] = 1;

	// 점화식
	// D[N][L][R] : N개의 빌딩이 있고, 왼쪽에서 보이는 개수 L 오른쪽에서 보이는 개수 R일때 가능한 경우의 수
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= L; ++j)
		{
			for (int k = 1; k <= R; ++k)
			{
				D[i][j][k] = (D[i - 1][j][k] * (i - 2) +
							   (D[i - 1][j][k - 1] +
							   D[i - 1][j - 1][k]))
							   % mod;
			}
		}
	}

	cout << D[N][L][R] << "\n";

	return 0;
}