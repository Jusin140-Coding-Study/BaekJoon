/*
* @title    : 11657번 타임머신(골드4)
* @content  : 벨만-포드
* @author   : 손동찬
* @date     : 240723
* @time     : 12 ms
* @memory   : 2332 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	int S;
	int E;
	int W;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<Data> vecEdgeList;
	for (int i = 0; i < M; ++i)
	{
		Data data;
		cin >> data.S >> data.E >> data.W;
		vecEdgeList.push_back(data);
	}

	vector<long long> vecTimes(N+1,60000001);
	vecTimes[1] = 0;

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < vecEdgeList.size(); ++j)
		{
			if (vecTimes[vecEdgeList[j].S] == 60000001) continue;
				
			if (vecTimes[vecEdgeList[j].E] > vecTimes[vecEdgeList[j].S] + vecEdgeList[j].W)
				vecTimes[vecEdgeList[j].E] = vecTimes[vecEdgeList[j].S] + vecEdgeList[j].W;
		}
	}

	bool isLoop = false;

	for (int j = 0; j < vecEdgeList.size(); ++j)
	{
		if (vecTimes[vecEdgeList[j].S] == 60000001) continue;

		if (vecTimes[vecEdgeList[j].E] > vecTimes[vecEdgeList[j].S] + vecEdgeList[j].W)
		{
			vecTimes[vecEdgeList[j].E] = vecTimes[vecEdgeList[j].S] + vecEdgeList[j].W;
			isLoop = true;
		}
	}

	if (isLoop)
	{
		cout << "-1";
		return 0;
	}

	for (int i = 2; i <= N; ++i)
	{
		if (vecTimes[i] == 60000001)
			cout << "-1\n";
		else
			cout << vecTimes[i] << "\n";
	}

	return 0;
}
