#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0);
	cin >> N;

	vector<int> V(N, 0);
	vector<int> R(N, 0);
	stack<int> S;

	for (int i = 0; i < N; ++i)
		cin >> V[i];

	for (int i = 0; i < N; ++i)
	{
		while (!S.empty() && V[S.top()] < V[i])
		{
			R[S.top()] = V[i];
			S.pop();
		}
		S.push(i);
	}

	while (!S.empty())
	{
		R[S.top()] = -1;
		S.pop();
	}

	for (auto num : R)
		cout << num << " ";
}