#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 그리디 알고리즘
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int OneCnt = 0;
	int ZeroCnt = 0;
	long long Result = 0;
	cin >> N;

	priority_queue<int> plusQ;
	priority_queue<int, vector<int>, greater<>> minusQ;

	for (int i = 0; i < N; ++i)
	{
		int Input = 0;
		cin >> Input;

		// 0
		if (0 == Input)
			ZeroCnt++;
		// 1
		else if (1 == Input)
			OneCnt++;
		// 양수
		else if (0 < Input)
			plusQ.push(Input);
		// 음수
		else if (0 > Input)
			minusQ.push(Input);
	}

	while (2 <= plusQ.size())
	{
		int firstTop = plusQ.top();
		plusQ.pop();
		int secondTop = plusQ.top();
		plusQ.pop();

		Result += firstTop * secondTop;
	}
	if (!plusQ.empty())
		Result += plusQ.top();

	while (2 <= minusQ.size())
	{
		int firstTop = minusQ.top();
		minusQ.pop();
		int secondTop = minusQ.top();
		minusQ.pop();

		Result += firstTop * secondTop;
	}
	if (!minusQ.empty())
	{
		if (0 == ZeroCnt)
		{
			Result += minusQ.top();
		}
	}

	Result += OneCnt;

	cout << Result;
	return 0;
}