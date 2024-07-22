#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N >> M;

	// 인접 리스트 초기화
	vector<vector<int>> NearList(N + 1, vector<int>());

	// 진입 차수 초기화
	vector<int> InDegree(N + 1, 0);

	// 줄 배열 초기화
	vector<int> Line;
	
	for (int i = 0; i < M; ++i)
	{
		int A = 0; int B = 0;
		cin >> A >> B;

		NearList[A].push_back(B);
		++InDegree[B]; // 진입 차수 증가
	}

	// 진입 차수가 0인 인덱스 찾기
	queue<int> Q;
	for (int i = 1; i <= N; ++i)
	{
		if (InDegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty())
	{
		int curNode = Q.front();
		Q.pop();
		Line.push_back(curNode);

		for (int i = 0; i < NearList[curNode].size(); ++i)
		{
			InDegree[NearList[curNode][i]]--;
			if (0 == InDegree[NearList[curNode][i]])
				Q.push(NearList[curNode][i]);
		}
	}

	for (int i = 0; i < Line.size(); ++i)
		cout << Line[i] << " ";
}