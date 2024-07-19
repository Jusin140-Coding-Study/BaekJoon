/*
* @title    : 2251번 물통(골드5)
* @content  : 그래프의 표현
* @author   : 손동찬
* @date     : 240719
* @time     : 0ms
* @memory   : 2156 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> vecSender	= { 0, 0, 1, 1, 2, 2 };
	vector<int> vecReceiver = { 1, 2, 0, 2, 0, 1 };

	vector<vector<bool>> vecVisited(201, vector<bool>(201, false));
	vector<bool> vecAnswer(201, false);
	vector<int> vecMax(3);
	
	cin >> vecMax[0] >> vecMax[1] >> vecMax[2];
	
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	vecVisited[0][0] = true;
	vecAnswer[vecMax[2]] = true;
	
	while (!que.empty())
	{
		pair<int, int> p = que.front();
		que.pop();
	
		int A = p.first;
		int B = p.second;
		int C = vecMax[2] - A - B;
	
		for (int i = 0; i < 6; ++i)
		{
			vector<int> vecNext = { A, B, C };
			vecNext[vecReceiver[i]] += vecNext[vecSender[i]];
			vecNext[vecSender[i]] = 0;

			if (vecNext[vecReceiver[i]] > vecMax[vecReceiver[i]])
			{
				vecNext[vecSender[i]] = vecNext[vecReceiver[i]] - vecMax[vecReceiver[i]];
				vecNext[vecReceiver[i]] = vecMax[vecReceiver[i]];
			}

			if (!vecVisited[vecNext[0]][vecNext[1]])
			{
				vecVisited[vecNext[0]][vecNext[1]] = true;
				que.push(make_pair(vecNext[0], vecNext[1]));

				if (vecNext[0] == 0)
					vecAnswer[vecNext[2]] = true;
			}
		}
	}

	for (int i = 0; i < 201; ++i)
		if(vecAnswer[i])
			cout << i << " ";
	
	return 0;
}
