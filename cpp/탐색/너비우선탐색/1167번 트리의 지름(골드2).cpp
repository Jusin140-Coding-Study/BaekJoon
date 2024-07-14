/*
* @title    : 1167번 트리의 지름(골드2)
* @content  : 너비우선탐색
* @author   : 손동찬
* @date     : 240714
* @time     : 80 ms
* @memory   : 9444 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(queue<int>& _que, vector<vector<pair<int, int>>>& _vecTree, vector<bool>& _vecCheck, vector<int>& _vecDistance)
{
	while (!_que.empty())
	{
		int iFront = _que.front();
		_que.pop();
		for (int i = 0; i < _vecTree[iFront].size(); ++i)
		{
			if (_vecCheck[_vecTree[iFront][i].first])
				continue;

			_vecCheck[_vecTree[iFront][i].first] = true;
			_que.push(_vecTree[iFront][i].first);
			_vecDistance[_vecTree[iFront][i].first] = _vecDistance[iFront] + _vecTree[iFront][i].second;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	cin >> V;
	vector<vector<pair<int, int>>> vecTree(V + 1);
	for (int i = 1; i <= V; ++i)
	{
		int a;
		cin >> a;

		while (1)
		{
			pair<int, int> p;
			cin >> p.first;
			if (p.first == -1) break;
			cin >> p.second;
			vecTree[a].push_back(p);
		}
	}
	vector<bool> vecCheck(V + 1, false);
	vector<int> vecDistance(V + 1, 0);
	queue<int> que;
	que.push(1);
	vecCheck[1] = true;
	vecDistance[1] = 0;
	BFS(que, vecTree, vecCheck, vecDistance);

	int max_index = max_element(vecDistance.begin(), vecDistance.end()) - vecDistance.begin();
	vecCheck.assign(vecCheck.size(), false);
	vecDistance.assign(vecDistance.size(), 0);
	que.push(max_index);
	vecCheck[max_index] = true;
	BFS(que, vecTree, vecCheck, vecDistance);

	int max = *max_element(vecDistance.begin(), vecDistance.end());

	cout << max << "\n";

	return 0;
}