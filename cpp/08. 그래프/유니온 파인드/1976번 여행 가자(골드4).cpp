/*
* @title    : 1976번 여행 가자(골드4)
* @content  : 유니온 파인드
* @author   : 손동찬
* @date     : 240720
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int Find(int a, vector<int>& _vecNums)
{
	if (a == _vecNums[a])
		return a;
	else
		return _vecNums[a] = Find(_vecNums[a], _vecNums);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> vecNums(N + 1);
	for (int i = 1; i <= N; ++i)
		vecNums[i] = i;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int Connection;
			cin >> Connection;
			if (j <= i) continue;

			if (Connection)
			{
				int TempA = Find(i, vecNums);
				int TempB = Find(j, vecNums);

				if (TempA != TempB)
					vecNums[TempB] = TempA;
			}
		}
	}

	int Front;
	cin >> Front;
	bool isConnect = true;
	for (int i = 2; i <= M; ++i)
	{
		int Next;
		cin >> Next;

		int TempA = Find(Front, vecNums);
		int TempB = Find(Next, vecNums);

		if (TempA != TempB)
		{
			isConnect = false;
			break;
		}
		Front = Next;
	}

	if (isConnect) cout << "YES";
	else cout << "NO";

	return 0;
}
