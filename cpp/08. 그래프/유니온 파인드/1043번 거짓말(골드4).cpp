/*
* @title    : 1043번 거짓말(골드4)
* @content  : 유니온 파인드
* @author   : 손동찬
* @date     : 240720
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int Find(int _a, vector<int>& _vecNums)
{
	if (_vecNums[_a] == _a)
		return _a;
	else
		return _vecNums[_a] = Find(_vecNums[_a], _vecNums);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> vecNums(N + 1);
	vector<vector<int>> vecParty(M);
	for (int i = 1; i <= N; ++i)
		vecNums[i] = i;

	int iKnows;
	cin >> iKnows;
	int Represent = 0;
	if (iKnows) 
		cin >> Represent;
	else
	{
		cout << M;
		return 0;;
	}

	for (int i = 1; i < iKnows; ++i)
	{
		int a;
		cin >> a;
		vecNums[a] = Represent;
	}

	for (int i = 0; i < M; ++i)
	{
		int a;
		cin >> a;
		if (a == 0) continue;
		int b;
		cin >> b;
		vecParty[i].push_back(b);
		for (int j = 1; j < a; ++j)
		{
			int c;
			cin >> c;
			vecParty[i].push_back(c);
			int TempA = Find(b, vecNums);
			int TempB = Find(c, vecNums);
			if(TempA != TempB)
				vecNums[TempB] = TempA;
		}
	}

	int iCount = 0;
	for (int i = 0; i < M; ++i)
	{
		bool bCheck = true;
		for (int j = 0; j < vecParty[i].size(); ++j)
		{
			int TempA = Find(Represent, vecNums);
			int TempB = Find(vecParty[i][j], vecNums);
			if (TempA == TempB)
			{
				bCheck = false;
				break;
			}
		}

		if (bCheck) iCount++;
	}

	cout << iCount;

	return 0;
}
