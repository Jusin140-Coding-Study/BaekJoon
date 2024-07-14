#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsExist(int num, vector<int>& v);

// ÀÌ°Ô ¹¹ÀÓ..?
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;
	cin >> N >> M;

	vector<int> V(N, 0);
	int start = 0;
	int end = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> V[i];
		if (start < V[i])
			start = V[i];

		end = end + V[i];
	}

	while (start <= end)
	{
		int middle = (start + end) / 2;
		int sum = 0;
		int count = 0;

		for (int i = 0; i < N; ++i)
		{
			if (sum + V[i] > middle)
			{
				count++;
				sum = 0;
			}
			sum = sum + V[i];
		}
		if (sum != 0)
		{
			count++;
		}
		if (count > M)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}

	cout << start << "\n";
}