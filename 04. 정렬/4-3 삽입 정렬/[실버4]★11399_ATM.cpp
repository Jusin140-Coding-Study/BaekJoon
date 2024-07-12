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
	for (int i = 0; i < N; ++i)
		cin >> V[i];

	for (int i = 1; i < N; ++i)
	{
		int InsertIndex = i;
		int InsertValue = V[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (V[j] < V[i])
			{
				InsertIndex = j + 1;
				break;
			}
			if (j == 0)
			{
				InsertIndex = 0;
			}
		}
		for (int j = i; j > InsertIndex; --j)
		{
			V[j] = V[j - 1];
		}
		V[InsertIndex] = InsertValue;
	}

	// 합 배열 만들기
	vector<int> S(N, 0);
	S[0] = V[0];
	for (int i = 1; i < N; ++i)
	{
		S[i] = S[i - 1] + V[i];
	}

	int Result(0);
	for (auto& n : S)
		Result += n;

	cout << Result;
}