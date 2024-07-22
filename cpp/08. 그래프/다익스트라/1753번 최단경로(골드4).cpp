/*
* @title    : 1753번 최단경로(골드4)
* @content  : 다익스트라
* @author   : 손동찬
* @date     : 240722
* @time     : 100 ms
* @memory   : 9112 KB
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

	int V, E;
	cin >> V >> E;
	int Start;
	cin >> Start;
	vector<vector<pair<int, int>>> vecDatas(V+1);
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vecDatas[u].push_back(make_pair(v, w));
	}

	vector<int> vecDistance(V + 1, 3000001);
	vector<bool> vecVisited(V + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;

	pQue.push(make_pair(0, Start));
	vecDistance[Start] = 0;
	while (!pQue.empty())
	{
		int index = pQue.top().second;
		pQue.pop();
		if (vecVisited[index]) continue;
		vecVisited[index] = true;

		for (int i = 0; i < vecDatas[index].size(); ++i)
		{
			if (vecDistance[vecDatas[index][i].first] > vecDistance[index] + vecDatas[index][i].second)
			{
				vecDistance[vecDatas[index][i].first] = vecDistance[index] + vecDatas[index][i].second;
				pQue.push(make_pair(vecDistance[vecDatas[index][i].first],vecDatas[index][i].first));
			}
		}
	}
	for (int i = 1; i <= V; ++i)
	{
		if(vecDistance[i] == 3000001)
			cout << "INF\n";
		else
			cout << vecDistance[i] << "\n";
	}
	return 0;
}
