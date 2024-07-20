/*
* @title    : 2346�� ǳ�� �Ͷ߸���(�ǹ�3)
* @content  : ����, ť, ��
* @author   : �յ���
* @date     : 240721
* @time     : 0ms
* @memory   : 2156 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	deque<pair<int, int>> deq;

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int iNum;
		cin >> iNum;
		deq.push_back(make_pair(i, iNum));
	}

	int Order = deq.front().second;
	cout << deq.front().first << " ";
	deq.pop_front();

	while (!deq.empty())
	{
		if (Order > 0)
		{
			for (int i = 1; i <= Order; ++i)
			{
				pair p = deq.front();
				deq.pop_front();
				if (i == Order)
				{
					Order = p.second;
					cout << p.first << " ";
					break;
				}
				deq.push_back(p);
			}
		}
		else
		{
			Order *= -1;
			for (int i = 1; i <= Order; ++i)
			{
				pair p = deq.back();
				deq.pop_back();
				if (i == Order)
				{
					Order = p.second;
					cout << p.first << " ";
					break;
				}
				deq.push_front(p);
			}
		}
	}


	return 0;
}
