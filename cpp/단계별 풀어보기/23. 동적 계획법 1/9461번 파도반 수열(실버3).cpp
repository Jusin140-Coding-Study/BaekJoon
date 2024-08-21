/*
* @title    : 9461번 파도반 수열(실버3)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240813
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

typedef  long long _long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	_long DP[101] = { 0,1,1,1,2,2,3,4,5,7,9, };
	for (int i = 11; i <= 100; ++i)
		DP[i] = DP[i - 1] + DP[i - 5];

	int T;
	cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		cout << DP[N] << "\n";
	}

	return 0;
}
