/*
* @title    : 1219번 오민식의 고민(플래티넘5)
* @content  : 벨만-포드
* @author   : 손동찬
* @date     : 240723
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <limits.h>

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

	int N, Start, End, M;
	cin >> N >> Start >> End >> M;
	vector<Data> vecDatas;
	vector<int> vecCharges(N);
	for (int i = 0; i < M; ++i)
	{
		Data d;
		cin >> d.S >> d.E >> d.W;
		vecDatas.push_back(d);
	}
	for (int i = 0; i < N; ++i)
		cin >> vecCharges[i];

	vector<long long> vecTotals(N, LLONG_MAX);
	vector<bool> vecCheck(N, false);

	vecTotals[Start] = vecCharges[Start];
	vecCheck[Start] = true;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < vecDatas.size(); ++j)
		{
			if (vecTotals[vecDatas[j].S] == LLONG_MAX) continue;

			if (!vecCheck[vecDatas[j].E])
			{
				vecTotals[vecDatas[j].E] = vecTotals[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E];
				vecCheck[vecDatas[j].E] = true;
			}
			else if (vecTotals[vecDatas[j].E] < vecTotals[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E])
				vecTotals[vecDatas[j].E] = vecTotals[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E];

		}
	}

	bool isLoop = false;
	vector<int> vecCycleV;
	for (int j = 0; j < vecDatas.size(); ++j)
	{
		if (vecTotals[vecDatas[j].S] == LLONG_MAX) continue;

		if (!vecCheck[vecDatas[j].E])
		{
			vecTotals[vecDatas[j].E] = vecTotals[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E];
			vecCheck[vecDatas[j].E] = true;
			vecCycleV.push_back(vecDatas[j].E);
			isLoop = true;
		}
		else if (vecTotals[vecDatas[j].E] < vecTotals[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E])
		{
			vecTotals[vecDatas[j].E] = vecTotals[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E];
			vecCycleV.push_back(vecDatas[j].E);
			isLoop = true;
		}
	}

	bool isCycle = false;
	for (int k = 0; k < vecCycleV.size(); ++k)
	{
	
		vector<long long> vecTotals2(N, LLONG_MAX);
		vector<bool> vecCheck2(N, false);
	
		vecTotals2[vecCycleV[k]] = vecCharges[vecCycleV[k]];
		vecCheck2[vecCycleV[k]] = true;
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = 0; j < vecDatas.size(); ++j)
			{
				if (vecTotals2[vecDatas[j].S] == LLONG_MAX) continue;
	
				if (!vecCheck2[vecDatas[j].E])
				{
					vecTotals2[vecDatas[j].E] = vecTotals2[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E];
					vecCheck2[vecDatas[j].E] = true;
				}
				else if (vecTotals2[vecDatas[j].E] < vecTotals2[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E])
					vecTotals2[vecDatas[j].E] = vecTotals2[vecDatas[j].S] - vecDatas[j].W + vecCharges[vecDatas[j].E];
	
			}
		}

		if (vecTotals2[End] != LLONG_MAX) //나 Gee다
		{
			isCycle = true;
			break;
		}
	}

	if (vecTotals[End] == LLONG_MAX)
		cout << "gg";

	else  if (isLoop && isCycle)
		cout << "Gee";
	
	else
		cout << vecTotals[End];

	return 0;
}
