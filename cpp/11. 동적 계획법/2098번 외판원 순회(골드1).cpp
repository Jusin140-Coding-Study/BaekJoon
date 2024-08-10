/*
* @title    : 2098번 외판원 순회(골드1)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240810
* @time     : 28 ms
* @memory   : 6116 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAX_COST 1000000*16 + 1

int N;
int cost[16][16];
int DP[16][1 << 16];

int TSP(int _C, int _V)
{
	if (_V == (1 << N) - 1)
		return cost[_C][0] == 0 ? MAX_COST : cost[_C][0];

	if (DP[_C][_V])  
		return DP[_C][_V];
	
	int iMin = MAX_COST;

	for (int i = 0; i < N; ++i)
		if ((_V & (1 << i)) == 0 && cost[_C][i] != 0)
			iMin = min(iMin, TSP(i, (_V | (1 << i))) + cost[_C][i]);
	
	return DP[_C][_V] = iMin;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> cost[i][j];

	cout << TSP(0, 1);

	return 0;
}