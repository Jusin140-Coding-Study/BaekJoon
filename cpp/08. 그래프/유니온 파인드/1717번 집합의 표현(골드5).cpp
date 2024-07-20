/*
* @title    : 1717번 집합의 표현(골드5)
* @content  : 유니온 파인드
* @author   : 손동찬
* @date     : 240720
* @time     : 40 ms
* @memory   : 5928 KB
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
	for (int i = 0; i <= N; ++i)
		vecNums[i] = i;

	for (int i = 0; i < M; ++i)
	{
		int iOrder, A, B;
		cin >> iOrder >> A >> B;

		if (iOrder)
		{
			int TempA = Find(A, vecNums);
			int TempB = Find(B, vecNums);

			if(TempA == TempB)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			int TempA = Find(A, vecNums);
			int TempB = Find(B, vecNums);

			if (TempA != TempB)
				vecNums[TempB] = TempA;
		}
	}

	return 0;
}
