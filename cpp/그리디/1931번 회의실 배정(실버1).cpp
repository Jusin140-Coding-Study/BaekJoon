/*
* @title    : 1931번 회의실 배정(실버1)
* @content  : 그리디
* @author   : 손동찬
* @date     : 240715
* @time     : 28 ms
* @memory   : 2804 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> vTimes(N);
	for (int i = 0; i < N; ++i)
		cin >> vTimes[i].second >> vTimes[i].first;
	
	sort(vTimes.begin(), vTimes.end());

	int iEndTime = 0;
	int iCount = 0;
	for (int i = 0; i < N; ++i)
	{
		if (vTimes[i].second >= iEndTime)
		{
			iEndTime = vTimes[i].first;
			iCount++;
		}
	}

	cout << iCount;

	return 0;
}
