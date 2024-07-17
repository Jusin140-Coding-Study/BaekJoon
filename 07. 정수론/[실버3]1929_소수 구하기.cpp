#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N >> M;

	vector<pair<int, bool>> V(M + 1, { 0, true });
	V[0] = { 0, false };
	V[1] = { 1, false };

	// '에라토스테네스의 체' 활용
	for (int i = 2; i <= M; ++i)
		V[i].first = i;

	for (int i = 2; i <= M; ++i)
	{
		for (int j = 2 * V[i].first; j <= M; j += V[i].first)
			V[j].second = false;
	}

	for (int i = N; i <= M; ++i)
	{
		if (V[i].second)
			cout << V[i].first << "\n";
	}

	return 0;
}