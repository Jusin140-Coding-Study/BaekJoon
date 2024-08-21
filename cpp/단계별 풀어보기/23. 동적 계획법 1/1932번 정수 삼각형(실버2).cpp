/*
* @title    : 1932번 정수 삼각형(실버2)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240814
* @time     : 8 ms
* @memory   : 2680 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>> DP(N+1);
	
	vector<int> vTemp(2, 0);
	DP[0] = vTemp;
	cin >> vTemp[1];
	DP[1] = vTemp;
	for (int i = 2; i <= N; ++i)
	{
		vector<int> v(i+1,0);
		DP[i] = v;

		for (int j = 1; j <= i; ++j)
		{
			int num;
			cin >> num;
			if (j == 1)
				DP[i][j] = DP[i - 1][j] + num;
			else if(j == i) 
				DP[i][j] = DP[i - 1][j - 1] + num;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + num;
		}
	}

	int Result = 0;
	for (int i = 1; i <= N; ++i)
		Result = max(Result, DP[N][i]);

	cout << Result;

	return 0;
}
