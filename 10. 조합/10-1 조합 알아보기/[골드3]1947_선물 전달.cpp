#include <iostream>
#include <vector>
using namespace std;

static vector<long long> D;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	D = vector<long long>(N + 1, 0);

	D[1] = 0;
	D[2] = 1;

	for (int i = 3; i <= N; ++i)
	{
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % 1'000'000'000;
	}

	cout << D[N];

	return 0;
}