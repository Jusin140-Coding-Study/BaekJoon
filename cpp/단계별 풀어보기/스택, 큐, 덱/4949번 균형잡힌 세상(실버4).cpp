/*
* @title    : 4949�� �������� ����(�ǹ�4)
* @content  : ����, ť, ��
* @author   : �յ���
* @date     : 240717
* @time     : 4 ms
* @memory   : 2024 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strSentence;
	getline(cin, strSentence);

	while (strSentence != ".")
	{
		stack<char> st;
		for (int i = 0; i < strSentence.size(); ++i)
		{
			if (strSentence[i] == '.')
				break;

			if (strSentence[i] =='[' || strSentence[i] == ']' || strSentence[i] == '(' || strSentence[i] == ')')
			{
				if (st.empty())
				{
					st.push(strSentence[i]);
					continue;
				}
				if ((st.top() == '[' && strSentence[i] == ']') || (st.top() == '(' && strSentence[i] == ')') )
				{
					st.pop();
					continue;
				}

				st.push(strSentence[i]);
			}
		}

		if (st.empty()) 
			cout << "yes" << "\n";
		else 
			cout << "no" << "\n";
		
		getline(cin, strSentence);
	}

	return 0;
}
