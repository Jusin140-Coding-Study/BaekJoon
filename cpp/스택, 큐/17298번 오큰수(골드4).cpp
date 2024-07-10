/*
* @title    : 17298번 오큰수(골드4)
* @content  : 스택, 큐
* @author   : 손동찬
* @date     : 240710
* @time     : 212 ms
* @memory   : 14120 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	
	stack<int> st;
	vector<int> vResult(N, -1);

	for (int i = 0; i < N; ++i)
	{
		if (st.empty())
		{
			st.push(i);
			continue;
		}
		else
		{
			while (!st.empty() && v[st.top()] < v[i])
			{
				vResult[st.top()] = v[i];
				st.pop();
			}
			st.push(i);
			continue;
		}
	}

	for (int& Result : vResult)
		cout << Result << " ";

	return 0;
}