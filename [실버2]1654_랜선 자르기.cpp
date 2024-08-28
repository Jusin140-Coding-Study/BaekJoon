#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> vecLines;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long K, N;
	cin >> K >> N;

	vecLines = vector<long long>(K, 0);

	for (int i = 0; i < K; ++i)
		cin >> vecLines[i];

	long long L = 1;
	long long R = pow(2, 31) - 1;

	while (L <= R)
	{
		long long iSumLines = 0;
		long long Middle = (L + R) / 2;

		for (const auto& line : vecLines)
			iSumLines += line / Middle;

		if (N <= iSumLines)
			L = Middle + 1;
		else
			R = Middle - 1;
	}

	cout << R << "\n";

	return 0;
}