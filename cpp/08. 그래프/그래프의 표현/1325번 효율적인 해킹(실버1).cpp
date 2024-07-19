/*
* @title    : 1325번 효율적인 해킹(실버1)
* @content  : 그래프의 표현
* @author   : 손동찬
* @date     : 240719
* @time     : 3748 ms
* @memory   : 3468 KB
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

	vector<vector<int>> AdjacencyList(N+1);
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		AdjacencyList[B].push_back(A);
	}

	vector<int> vecResult(N + 1);
	vector<bool> vecCheck(N + 1, false);
	queue<int> queNums;
	for (int i = 1; i <= N; ++i)
	{
		int iCount = 1;
		queNums.push(i);
		vecCheck.assign(N+1, false);
		vecCheck[i] = true;
		while(!queNums.empty())
		{
			int iFront = queNums.front();
			queNums.pop();
			
			for (int i = 0; i < AdjacencyList[iFront].size(); ++i)
			{
				if (vecCheck[AdjacencyList[iFront][i]])
					continue;

				vecCheck[AdjacencyList[iFront][i]] = true;
				queNums.push(AdjacencyList[iFront][i]);
				iCount++;
			}

		}

		vecResult[i] = iCount;
	}

	int iMax = 0;
	for (int i = 1; i <= N; ++i)
		iMax = max(vecResult[i], iMax);

	
	for (int i = 1; i <= N; ++i)
		if (vecResult[i] == iMax)
			cout << i << " ";

	return 0;
}
