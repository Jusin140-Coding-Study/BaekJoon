/*
* @title    : 9012번 괄호(실버4)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240717
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		stack<char> st;
		string strPS;
		cin >> strPS;
		for (int j = 0; j < strPS.size(); ++j)
		{
			if (st.empty())
			{
				st.push(strPS[j]);
				continue;
			}

			if (st.top() == '(' && strPS[j] == ')')
			{
				st.pop();
				continue;
			}

			st.push(strPS[j]);	
		}

		if (st.empty())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}
