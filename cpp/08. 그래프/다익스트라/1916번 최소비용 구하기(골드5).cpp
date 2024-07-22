/*
* @title    : 1916번 최소비용 구하기(골드5)
* @content  : 다익스트라
* @author   : 손동찬
* @date     : 240722
* @time     : 36 ms
* @memory   : 4748 KB
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

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> vecDatas(N+1);
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		vecDatas[A].push_back(make_pair(B, C));
	}
	int Start, End;
	cin >> Start >> End;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;
	pQue.push(make_pair(0, Start));
	vector<int> vecCharge(N + 1, 99999999);
	vecCharge[Start] = 0;
	vector<bool> vecVisited(N + 1, false);
	while (!pQue.empty())
	{
		int index = pQue.top().second;
		pQue.pop();

		if (vecVisited[index]) continue;
		vecVisited[index] = true;

		for (int i = 0; i < vecDatas[index].size(); ++i)
		{
			if (vecCharge[vecDatas[index][i].first] > vecDatas[index][i].second + vecCharge[index])
			{
				vecCharge[vecDatas[index][i].first] = vecDatas[index][i].second + vecCharge[index];
				pQue.push(make_pair(vecCharge[vecDatas[index][i].first], vecDatas[index][i].first));
			}
		}
	}

	cout << vecCharge[End];

	return 0;
}
