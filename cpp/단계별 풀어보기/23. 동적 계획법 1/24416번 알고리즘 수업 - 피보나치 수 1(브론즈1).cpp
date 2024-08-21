/*
* @title    : 24416번 알고리즘 수업 - 피보나치 수 1(브론즈1)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240813
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int DP[41] = { 0, 1, 1, };

	int N;
	cin >> N;

	int DP_Count = 0;
	for (int i = 3; i <= N; ++i)
	{
		++DP_Count;
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N] << " " << DP_Count;

	return 0;
}
