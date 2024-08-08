#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> MinNum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	MinNum = vector<int>(N + 1, 0);
	MinNum[1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		MinNum[i] = MinNum[i - 1] + 1;

		if (i % 2 == 0)
		{
			MinNum[i] = min(MinNum[i], MinNum[i / 2] + 1);
		}

		if (i % 3 == 0)
		{
			MinNum[i] = min(MinNum[i], MinNum[i / 3] + 1);
		}
	}

	cout << MinNum[N];

	return 0;
}