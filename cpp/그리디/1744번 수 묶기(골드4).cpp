/*
* @title    : 1744번 수 묶기(골드4)
* @content  : 그리디
* @author   : 손동찬
* @date     : 240715
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;
		pq.push(iNum);
	}
	int iResult = 0;
	while (!pq.empty() && pq.top()<= 0)
	{
		int a = pq.top();
		pq.pop();

		if (pq.empty())
		{
			iResult += a;
			break;
		}

		if ((a * pq.top()) > a + pq.top())
		{
			iResult += (a * pq.top());
			pq.pop();
		}
		else
			iResult += a;
	}

	if (pq.empty())
	{
		cout << iResult;
		return 0;
	}
	
	stack<int> st;
	while (!pq.empty())
	{
		int a = pq.top();
		pq.pop();
		st.push(a);
	}
	while (!st.empty())
	{
		int a = st.top();
		st.pop();

		if (st.empty())
		{
			iResult += a;
			break;
		}

		if ((a * st.top()) > a + st.top())
		{
			iResult += (a * st.top());
			st.pop();
		}
		else
			iResult += a;
	}
	cout << iResult;
	return 0;
}
