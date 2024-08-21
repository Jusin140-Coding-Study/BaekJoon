/*
* @title    : 11054번 가장 긴 바이토닉 부분 수열(골드4)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240821
* @time     :  ms
* @memory   :  KB
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
	vector<int> Datas(N);
	vector<int> DP_Upper(N, 1);
	vector<int> DP_Lower(N, 1);

	for (int i = 0; i < N; ++i)
		cin >> Datas[i];

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Datas[i] > Datas[j])
				DP_Upper[i] = max(DP_Upper[i], DP_Upper[j] + 1);
		}
	}

	for (int i = N - 2; i >= 0; --i)
	{
		for (int j = N - 1; j > i; --j)
		{
			if (Datas[i] > Datas[j])
				DP_Lower[i] = max(DP_Lower[i], DP_Lower[j] + 1);
		}
	}

	int Result = 0;
	for (int i = 0; i < N; ++i)
		Result = max(Result, DP_Upper[i] + DP_Lower[i]);
	
	cout << Result - 1;

	return 0;
}
