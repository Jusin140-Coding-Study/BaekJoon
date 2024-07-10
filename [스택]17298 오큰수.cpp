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

	vector<int> Origin(N, 0);
	vector<int> Answer(N, 0);
	stack<int> Stack;

	for (int i = 0; i < N; ++i)
	{
		cin >> Origin[i];
	}
	Stack.push(0);

	for (int i = 0; i < N; ++i)
	{
		while (!Stack.empty() && Origin[Stack.top()] < Origin[i])
		{
			Answer[Stack.top()] = Origin[i];
			Stack.pop();
		}

		Stack.push(i);
	}

	while (!Stack.empty())
	{
		Answer[Stack.top()] = -1;
		Stack.pop();
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Answer[i] << " ";
	}

	return 0;
}