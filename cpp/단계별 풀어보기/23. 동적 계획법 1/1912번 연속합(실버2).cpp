/*
* @title    : 1912번 연속합(실버2)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240813
* @time     : 8ms
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
	bool b = false;
	vector<int> Data(N+1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> Data[i];
		if (!b && Data[i] >= 0)
			b = true;
	}
	
	if (!b)
	{
		cout << *max_element(Data.begin() + 1, Data.end());
		return 0;
	}

	vector<int> DP(N+1);
	int iMax = -1000;
	for (int i = 1; i <= N; ++i)
	{
		int Sum = DP[i - 1] + Data[i];
		DP[i] = max(Sum, 0);
		iMax = max(iMax, DP[i]);
	}
	
	cout << iMax;

	return 0;
}
