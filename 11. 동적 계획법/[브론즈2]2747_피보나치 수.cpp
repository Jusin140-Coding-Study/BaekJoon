#include <iostream>
#include <vector>
using namespace std;

static vector<int> TDFibonachi;
static vector<int> BUFibonachi;

int TopDownFibo(int n);
void BottomUpFibo(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	TDFibonachi = vector<int>(N + 1, -1);
	BUFibonachi = vector<int>(N + 1, -1);

	TDFibonachi[0] = 0;
	BUFibonachi[0] = 0;
	TDFibonachi[1] = 1;
	BUFibonachi[1] = 1;

	TopDownFibo(N);
	BottomUpFibo(N);

	// cout << TDFibonachi[N] << "\n";
	cout << BUFibonachi[N] << "\n";

	return 0;
}

int TopDownFibo(int n)
{
	if (-1 != TDFibonachi[n])
		return TDFibonachi[n];
	else
	{
		return TDFibonachi[n] = TopDownFibo(n - 1) + TopDownFibo(n - 2);
	}
}

void BottomUpFibo(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		BUFibonachi[i] = BUFibonachi[i - 1] + BUFibonachi[i - 2];
	}
}