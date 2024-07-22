/*
* @title    : 1854번 K번째 최단경로 찾기(플래티넘5)
* @content  : 다익스트라
* @author   : 손동찬
* @date     : 240722
* @time     : 116 ms
* @memory   : 6172 KB
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

	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<pair<int, int>>> vecDatas(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vecDatas[a].push_back(make_pair(b,c));
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;
	pQue.push(make_pair(0, 1));
	vector<priority_queue<int>> vecVisited(N+1);
	vecVisited[1].push(0);

	while (!pQue.empty())
	{
		int value = pQue.top().first;
		int index = pQue.top().second;
		pQue.pop();

		for (int i = 0; i < vecDatas[index].size(); ++i)
		{
			if (vecVisited[vecDatas[index][i].first].size() < K)
			{
				vecVisited[vecDatas[index][i].first].push(vecDatas[index][i].second + value);
				pQue.push(make_pair(vecDatas[index][i].second + value, vecDatas[index][i].first));
			}
			else
			{
				if (vecVisited[vecDatas[index][i].first].top() > vecDatas[index][i].second + value)
				{
					vecVisited[vecDatas[index][i].first].pop();
					vecVisited[vecDatas[index][i].first].push(vecDatas[index][i].second + value);
					pQue.push(make_pair(vecDatas[index][i].second + value, vecDatas[index][i].first));
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (vecVisited[i].size() == K)
			cout << vecVisited[i].top() << "\n";
		
		else
			cout << "-1\n";
	}

	return 0;
}
