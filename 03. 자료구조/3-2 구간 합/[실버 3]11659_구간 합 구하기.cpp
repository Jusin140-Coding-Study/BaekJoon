#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int M(0);
	cin >> N >> M;

	vector<int> vecSums(N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		int Input(0);
		cin >> Input;
		
		vecSums[i] = vecSums[i - 1] + Input;
	}

	for (int i = 0; i < M; ++i)
	{
		int Start(0); int End(0);
		cin >> Start >> End;

		cout << vecSums[End] - vecSums[Start - 1] << "\n";
	}
}