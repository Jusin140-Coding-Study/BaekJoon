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

	vector<int> V(N, 0);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j)
		{
			if (V[j] > V[j + 1])
			{
				int Temp = V[j];
				V[j] = V[j + 1];
				V[j + 1] = Temp;
			}
		}
	}

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << "\n";
	}
}