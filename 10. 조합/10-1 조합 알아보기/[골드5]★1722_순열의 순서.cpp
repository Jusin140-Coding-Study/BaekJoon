#include <iostream>
#include <vector>
using namespace std;

static vector<long long> Factorial;
static vector<bool> Visited;
static vector<int> Result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	Visited = vector<bool>(N + 1, false);
	Factorial = vector<long long>(N + 1, 0);
	Factorial[0] = 1;
	for (int i = 1; i <= N; ++i)
		Factorial[i] = Factorial[i - 1] * i;

	int Quiz = 0;
	cin >> Quiz;

	Result = vector<int>(N + 1, 0);

	switch (Quiz)
	{
	case 1:
	{
		// K번째 순열 구해서 출력
		long long K = 0;
		cin >> K;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1, cnt = 1; j <= N; ++j)
			{
				if (Visited[j]) continue;

				if (K <= cnt * Factorial[N - i])
				{
					K -= ((cnt - 1) * Factorial[N - i]);
					Result[i] = j;
					Visited[j] = true;
					break;
				}
				++cnt;
			}
		}

		for (int i = 1; i <= N; ++i)
			cout << Result[i] << " ";

		break;
	}
	case 2:
	{
		long long K = 1;
		
		for (int i = 1; i <= N; ++i)
		{
			cin >> Result[i];
			long long cnt = 0;

			for (int j = 1; j < Result[i]; ++j)
			{
				if (!Visited[j])
					++cnt;
			}

			K += cnt * Factorial[N - i];
			Visited[Result[i]] = true;
		}

		cout << K << "\n";

		break;
	}
	}

	return 0;
}