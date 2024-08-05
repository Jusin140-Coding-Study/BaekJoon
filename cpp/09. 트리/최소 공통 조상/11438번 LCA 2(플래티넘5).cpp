/*
* @title    : 11438번 LCA 2(플래티넘5)
* @content  : 최소 공통 조상
* @author   : 손동찬
* @date     : 240730
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int K = 0;
int iDepth = 0;
vector<vector<int>> vecNums;
int Parents[100001][21];
vector<int> vecDepth;
vector<int> vecVisited;

void BFS()
{
	queue<int> queNums;
	queue<int> queTemp;
	queNums.push(1);
	vecVisited[1] = true;
	//int Dep = 0;
	while (1)
	{
		++iDepth;
		while (!queNums.empty())
		{
			int iFront = queNums.front();
			queNums.pop();
			for (int i = 0; i < vecNums[iFront].size(); ++i)
			{
				if (vecVisited[vecNums[iFront][i]])
					continue;
				vecVisited[vecNums[iFront][i]] = true;
				Parents[vecNums[iFront][i]][0] = iFront;
				vecDepth[vecNums[iFront][i]] = iDepth;
				queTemp.push(vecNums[iFront][i]);
			}
		}

		if (queTemp.empty()) break;

		while (!queTemp.empty())
		{
			queNums.push(queTemp.front());
			queTemp.pop();
		}
	}
}

int LCA(int _A, int _B)
{
	if (vecDepth[_A] > vecDepth[_B])
	{
		int iTemp = _A;
		_A = _B;
		_B = iTemp;
	}

	for (int i = K; i >= 0; --i)
	{
		if (pow(2, i) <= vecDepth[_B] - vecDepth[_A])
			if (vecDepth[_A] <= vecDepth[Parents[_B][i]])
				_B = Parents[_B][i];
	}

	for (int i = K; i >= 0 && _A != _B; --i)
	{
		if (Parents[_A][i] != Parents[_B][i])
		{
			_A = Parents[_A][i];
			_B = Parents[_B][i];
		}
	}

	if (_A != _B)
		return Parents[_A][0];

	return _A;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vecNums.resize(N + 1);
	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		vecNums[a].push_back(b);
		vecNums[b].push_back(a);
	}
	vecDepth.resize(N + 1);
	vecVisited.resize(N + 1, false);

	BFS();

	while (iDepth > pow(2, K))
		++K;
	--K;

	for (int i = 1; i <= K; ++i)
		for (int j = 1; j <= N; ++j)
				Parents[j][i] = Parents[Parents[j][i-1]][i - 1];
	
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}

	return 0;
}
