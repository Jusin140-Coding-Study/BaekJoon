/*
* @title    : 1874번 스택 수열(실버2)
* @content  : 스택, 큐
* @author   : 손동찬
* @date     : 240710
* @time     : 20 ms
* @memory   : 2944 KB
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

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	stack<int> st;
	int iNum = 1;
	vector<char> vResult;
	for (int& i : v)
	{
		if (i >= iNum)
		{
			while (i >= iNum)
			{
				st.push(iNum);
				vResult.push_back('+');
				iNum++;
			}
			st.pop();
			vResult.push_back('-');
			continue;
		}
		else
		{
			if (st.empty())
			{
				cout << "NO" << "\n";
				return 0;
			}
			while (i < st.top())
			{
				st.pop();
				vResult.push_back('-');
			}
			if (i == st.top())
			{
				st.pop();
				vResult.push_back('-');
				continue;
			}
			cout << "NO" << "\n";
			return 0;
		}		
	}

	for (char& c : vResult)
		cout << c << "\n";

	return 0;
}