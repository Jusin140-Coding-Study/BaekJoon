/*
* @title    : 2252�� �� �����(���3)
* @content  : ���� ����
* @author   : �յ���
* @date     : 240721
* @time     : 28 ms
* @memory   : 3944 KB
* @state    : �Ϸ�
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
	vector<vector<int>> vecNums(N + 1);
	vector<int> vecCounts(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		vecNums[A].push_back(B);
		++vecCounts[B];
	}

	queue<int> queStudents;
	for (int i = 1; i <= N; ++i)
	{
		if (!vecCounts[i])
			queStudents.push(i);
	}

	while (!queStudents.empty())
	{
		int iNum = queStudents.front();
		queStudents.pop();
		cout << iNum << " ";
		for (int i = 0; i < vecNums[iNum].size(); ++i)
		{
			--vecCounts[vecNums[iNum][i]];
			if(!vecCounts[vecNums[iNum][i]])
				queStudents.push(vecNums[iNum][i]);
		}	
	}

	return 0;
}
