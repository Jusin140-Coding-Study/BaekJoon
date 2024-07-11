#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int M(0); long long Answer(0);
	cin >> N >> M;

	vector<long long> S(N, 0);
	vector<long long> C(M, 0);

	cin >> S[0];
	for (int i = 1; i < N; ++i)
	{
		int Input(0);
		cin >> Input;
		S[i] = S[i - 1] + Input;
	}

	for (int i = 0; i < N; ++i)
	{
		S[i] %= M;
		if (S[i] == 0)
			Answer++;

		C[S[i]]++;
	}

	for (int i = 0; i < M; ++i)
	{
		if (C[i] > 1)
			Answer = Answer + C[i] * (C[i] - 1) / 2;
	}

	cout << Answer << "\n";
}