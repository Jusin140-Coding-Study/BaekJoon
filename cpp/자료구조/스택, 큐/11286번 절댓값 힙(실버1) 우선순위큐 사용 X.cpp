/*
* @title    : 11286번 절댓값 힙(실버1) 우선순위큐 사용 X
* @content  : 스택, 큐
* @author   : 손동찬
* @date     : 240710
* @time     : 28 ms
* @memory   : 4928 KB
* @state    : 완료
*/
#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	multimap<int, bool> m;
	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum == 0)
		{
			if (m.empty())
			{
				cout << "0" << "\n";
				continue;
			}
			if (m.begin()->second == false)
			{
				cout << -(m.begin()->first) << "\n";
				m.erase(m.begin());
				continue;
			}
			int a = m.begin()->first;
			auto range = m.equal_range(a);
			bool bCheck = true;
			for (auto iter = range.first; iter != range.second; ++iter) 
			{
				if (iter->second == false)
				{
					cout << -(iter->first) << "\n";
					m.erase(iter);
					bCheck = false;
					break;
				}
			}
			if (bCheck)
			{
				cout << m.begin()->first << "\n";
				m.erase(m.begin());
			}
		}
		else
		{
			if (iNum > 0) m.emplace(iNum, true);
			else m.emplace(-iNum, false);	
		}
	}

	return 0;
}