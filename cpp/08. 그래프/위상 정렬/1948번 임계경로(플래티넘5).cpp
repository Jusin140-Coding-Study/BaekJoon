/*
* @title    : 1948번 임계경로(플래티넘5)
* @content  : 위상 정렬
* @author   : 손동찬
* @date     : 240722
* @time     : 28 ms
* @memory   : 5176 KB
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
	vector<vector<pair<int, int>>> vecDataOri(N + 1);
	vector<int> vecCountOri(N + 1);
	vector<vector<pair<int, int>>> vecDataRev(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		vecDataOri[A].push_back(make_pair(B, C));
		++vecCountOri[B];
		vecDataRev[B].push_back(make_pair(A, C));
	}
	int Start, End;
	cin >> Start >> End;

	vector<int> vecMaxDistance(N + 1, 0);
	queue<int> que;
	que.push(Start);
	while (!que.empty())
	{
		int Num = que.front();
		que.pop();
		for (int i = 0; i < vecDataOri[Num].size(); ++i)
		{
			if (vecMaxDistance[vecDataOri[Num][i].first] < vecMaxDistance[Num] + vecDataOri[Num][i].second)
				vecMaxDistance[vecDataOri[Num][i].first] = vecMaxDistance[Num] + vecDataOri[Num][i].second;

			--vecCountOri[vecDataOri[Num][i].first];
			if (!vecCountOri[vecDataOri[Num][i].first])
				que.push(vecDataOri[Num][i].first);
		}
	}

	
	vector<bool> vecVisited(N + 1, false);
	vecVisited[End] = true;
	que.push(End);
	int iCount = 0;
	while (!que.empty())
	{
		int Num = que.front();
		que.pop();
		for (int i = 0; i < vecDataRev[Num].size(); ++i)
		{
			if (vecMaxDistance[Num] == vecMaxDistance[vecDataRev[Num][i].first] + vecDataRev[Num][i].second)
			{
				++iCount;
				if (!vecVisited[vecDataRev[Num][i].first])
				{
					vecVisited[vecDataRev[Num][i].first] = true;
					que.push(vecDataRev[Num][i].first);
				}
			}
		}	
	}

	cout << vecMaxDistance[End] << "\n" << iCount;

	return 0;
}
