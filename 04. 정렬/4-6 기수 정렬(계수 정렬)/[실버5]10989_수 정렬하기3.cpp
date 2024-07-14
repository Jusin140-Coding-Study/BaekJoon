#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0);
	cin >> N;

	vector<int> R(10001, 0);

	for (int i = 1; i <= N; ++i)
	{
		int temp(0);
		cin >> temp;

		R[temp]++;
	}

	for (int i = 1; i <= 10000; ++i)
	{
		if (R[i] != 0)
		{
			for (int j = 0; j < R[i]; ++j)
				cout << i << "\n";
		}
	}
}