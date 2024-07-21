/*
* @title    : 12789�� ��Ű��Ű ���ĵ帮��(�ǹ�3)
* @content  : ����, ť, ��
* @author   : �յ���
* @date     : 240717
* @time     : 0ms
* @memory   : 2024 KB
* @state    : �Ϸ�
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

	queue<int> que;
	stack<int> sta;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		que.push(num);
	}

	for (int i = 1; i <= N; ++i)
	{
		while (1)
		{
			if (que.empty())
			{
				if (sta.top() == i)
				{
					sta.pop();
					break;
				}
				else
				{
					cout << "Sad";
					return 0;
				}
			}
			else
			{
				if (que.front() == i)
				{
					que.pop();
					break;
				}
				else if (!sta.empty() && sta.top() == i)
				{
					sta.pop();
					break;
				}
				else
				{
					int Temp = que.front();
					que.pop();
					sta.push(Temp);
				}
			}
		}
	}

	if(sta.empty())
		cout << "Nice";
	else
		cout << "Sad";

	return 0;
}
