#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int M(0); int Result(0);
	cin >> N;
	cin >> M;

	vector<int> V(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> V[i];

	sort(V.begin(), V.end());

	auto Start = V.begin();
	auto End = V.end() - 1;

	while (*Start < *End)
	{
		int Sum = *Start + *End;

		if (Sum == M)
		{
			Result++;
			Start++;
			End--;
		}
		else if (Sum < M)
		{
			Start++;
		}
		else
		{
			End++;
		}
	}

	cout << Result;
}