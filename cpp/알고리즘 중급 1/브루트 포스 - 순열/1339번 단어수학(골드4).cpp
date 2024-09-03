/*
* @title    : 1339번 단어수학(골드4)
* @content  : 브루트 포스 - 순열
* @author   : 손동찬
* @date     : 240822
* @time     : 0ms
* @memory   : 2216 KB
* @state    : 완료
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	map<char, int> mapWeights;
	for (int i = 0; i < N; ++i)
	{
		string strWord = "";
		cin >> strWord;
		int Size = strWord.size();

		for (int j = 0; j < Size; ++j)
			mapWeights[strWord[j]] += pow(10, Size-j-1);
	}
	
	vector<int> vecWeights;
	for (auto p : mapWeights)
		vecWeights.push_back(p.second);

	sort(vecWeights.rbegin(), vecWeights.rend());

	int Result = 0;
	
	for (int i = 0; i < vecWeights.size(); ++i)
		Result += vecWeights[i] * (9 - i);

	cout << Result;

	return 0;
}
