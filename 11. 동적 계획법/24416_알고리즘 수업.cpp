#include <iostream>
#include <vector>
using namespace std;

static long D[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	D[1] = D[2] = 1;
	for (int i = 3; i <= 40; ++i)
		D[i] = D[i - 1] + D[i - 2];

	cout << D[N] << " " << N - 2 << "\n";

	return 0;
}