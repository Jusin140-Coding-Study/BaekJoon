/*
* @title    : 9251번 LCS(골드5)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240820
* @time     : 4 ms
* @memory   : 5932 KB
* @state    : 완료
*/
#include <iostream>
#include <string>

using namespace std;

int DP[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;
	int iSizeA = A.size();
	int iSizeB = B.size();

	bool a = false;
	for (int i = 0; i < iSizeA; ++i)
	{
		if (!a && B[0] == A[i])
			a = true;
		if (a) DP[i][0] = 1;
	}

	bool b = false;
	for (int i = 0; i < iSizeB; ++i)
	{
		if (!b && A[0] == B[i])
			b = true;
		if (b) DP[0][i] = 1;
	}

	for (int i = 1; i < iSizeA; ++i)
	{
		for (int j = 1; j < iSizeB; ++j)
		{
			if (A[i] == B[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[iSizeA - 1][iSizeB - 1];

	return 0;
}