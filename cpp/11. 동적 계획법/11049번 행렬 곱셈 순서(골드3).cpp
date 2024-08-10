/*
* @title    : 11049¹ø Çà·Ä °ö¼À ¼ø¼­(°ñµå3)
* @content  : µ¿Àû °èÈ¹¹ý
* @author   : ¼Õµ¿Âù
* @date     : 240810
* @time     : 124 ms
* @memory   : 3000 KB
* @state    : ¿Ï·á
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> vecMats;
int DP[501][501];

int Cal(int _F, int _S)
{
	if (DP[_F][_S] != -1) 
		return DP[_F][_S];

	if (_F == _S)
		return DP[_F][_S] = 0;

	if (_F + 1 == _S)
		return DP[_F][_S] = vecMats[_F].first * vecMats[_S].first * vecMats[_S].second;

	int iResult = INT_MAX;
	for (int i = _F; i < _S; ++i)
	{
		iResult = min(iResult,
			Cal(_F, i) + Cal(i + 1, _S)
			+ vecMats[_F].first * vecMats[i + 1].first * vecMats[_S].second);
	}

	return DP[_F][_S] = iResult;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vecMats.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		vecMats[i] = p;
	}
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			DP[i][j] = -1;
	
	cout << Cal(1, N);

	return 0;
}