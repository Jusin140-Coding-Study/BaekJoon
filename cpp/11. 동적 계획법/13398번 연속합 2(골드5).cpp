/*
* @title    : 13398번 연속합 2(골드5)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240808
* @time     : 8ms
* @memory   : 3196 KB
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
	vector<int> DP(N), LDP(N), RDP(N);

	for (int i = 0; i < N; ++i)
		cin >> DP[i];

	LDP[0] = DP[0];
	int iMax = LDP[0];
	for (int i = 1; i < N; ++i)
	{
		LDP[i] = max(DP[i], LDP[i - 1] + DP[i]);
		iMax = max(iMax, LDP[i]);
	}

	RDP[N - 1] = DP[N - 1];
	for (int i = N-2; i > 0; --i)
		RDP[i] = max(DP[i], RDP[i + 1] + DP[i]);
	
	for (int i = 1; i < N-1; ++i)
		iMax = max(iMax, LDP[i - 1] + RDP[i + 1]);
	
	cout << iMax;

	return 0;
}