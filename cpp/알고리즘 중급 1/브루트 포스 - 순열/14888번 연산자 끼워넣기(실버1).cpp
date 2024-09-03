/*
* @title    : 14888번 연산자 끼워넣기(실버1)
* @content  : 브루트 포스 - 순열
* @author   : 손동찬
* @date     : 240824
* @time     : 0ms
* @memory   : 2020 KB
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
	vector<int> vecNums(N);
	vector<int> vecCals;
	for (int i = 0; i < N; ++i)
		cin >> vecNums[i];
	
	int Num = 0;
	for (int i = 0; i < 4; ++i)
	{
		cin >> Num;
		for (int j = 0; j < Num; ++j)
			vecCals.push_back(i);
	}

	int MaxResult = -1000000001;
	int MinResult = 1000000001;
	int CalNum = 1;;
	while (1)
	{
		CalNum = vecNums[0];
		for (int i = 1; i < N; ++i)
		{
			if(vecCals[i-1] == 0) CalNum += vecNums[i];				
			else if (vecCals[i - 1] == 1) CalNum -= vecNums[i];				
			else if (vecCals[i - 1] == 2) CalNum *= vecNums[i];			
			else CalNum /= vecNums[i];			
		}
		MaxResult = max(MaxResult, CalNum);
		MinResult = min(MinResult, CalNum);

		if (!next_permutation(vecCals.begin(), vecCals.end()))
			break;
	}

	cout << MaxResult << "\n" << MinResult;

	return 0;
}
