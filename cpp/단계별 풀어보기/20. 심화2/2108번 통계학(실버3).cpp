/*
* @title    : 2108번 통계학(실버3)
* @content  : 심화 2
* @author   : 손동찬
* @date     : 240724
* @time     : 100 ms
* @memory   : 4384 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> vecNums(N);
	unordered_map<int, int> umFrequency;
	vector<int> vecAnswers(4);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecNums[i];
		umFrequency[vecNums[i]]++;
	}
	int sum = accumulate(vecNums.begin(), vecNums.end(), 0);
	vecAnswers[0] = sum / N;
	int num = sum % N;
	vecAnswers[0] += (num * 2) / N;

	sort(vecNums.begin(), vecNums.end());
	int Index = N / 2;
	vecAnswers[1] = vecNums[Index];

	int maxFreq = 0;
	for (const auto& a : umFrequency) 
	{
		if (a.second > maxFreq) 
		{
			maxFreq = a.second;
		}
	}
	vector<int> vecMaxValues;
	for (const auto& a : umFrequency)
	{
		if (a.second == maxFreq) 
		{
			vecMaxValues.push_back(a.first);
		}
	}
	if (vecMaxValues.size() == 1) vecAnswers[2] = vecMaxValues[0];
	else
	{
		sort(vecMaxValues.begin(), vecMaxValues.end());
		vecAnswers[2] = vecMaxValues[1];
	}

	vecAnswers[3] = vecNums[N - 1] - vecNums[0];


	for (int i = 0; i < 4; ++i)
		cout << vecAnswers[i] << "\n";

	return 0;
}
