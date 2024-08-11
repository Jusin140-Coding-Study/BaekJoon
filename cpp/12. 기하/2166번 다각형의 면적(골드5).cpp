/*
* @title    : 2166번 다각형의 면적(골드5)
* @content  : 기하
* @author   : 손동찬
* @date     : 240811
* @time     : 0ms
* @memory   : 2180 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long _long;

_long Extent(_long _X1, _long _Y1, _long _X2, _long _Y2)
{
	return (_X1 * _Y2)  - (_X2 * _Y1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(1);

	int N;
	cin >> N;
	vector<pair<_long, _long>> vecDots(N+1);
	
	for (int i = 0; i < N; ++i)
		cin >> vecDots[i].first >> vecDots[i].second;
	vecDots[N] = vecDots[0];
	
	double fResult = 0.f;
	for (int i = 0; i < N; ++i)
		fResult += Extent(vecDots[i].first, vecDots[i].second, vecDots[i+1].first, vecDots[i+1].second);

	cout << abs(fResult)/2.f;

	return 0;
}