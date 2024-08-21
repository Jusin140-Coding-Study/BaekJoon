/*
* @title    : 2579번 계단 오르기(실버3)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240819
* @time     : 0ms
* @memory   : 2020 KB
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
	vector<int> Datas(N + 1, 0);
	vector<int> DP(N + 1, 0);
	for (int i = 1; i <= N; ++i)
		cin >> Datas[i];

	DP[1] = Datas[1];
	DP[2] = Datas[1] + Datas[2];

	for (int i = 3; i <= N; ++i)
		DP[i] = max(DP[i - 2] + Datas[i], DP[i - 3] + Datas[i - 1] + Datas[i]);
	
	cout << DP[N];

	return 0;
}
