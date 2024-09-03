/*
* @title    : 1339�� �ܾ����(���4)
* @content  : ���Ʈ ���� - ����
* @author   : �յ���
* @date     : 240822
* @time     : 0ms
* @memory   : 2216 KB
* @state    : �Ϸ�
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
