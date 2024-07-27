/*
* @title    : 20920번 영단어 암기는 괴로워(실버3)
* @content  : 심화 2
* @author   : 손동찬
* @date     : 240726
* @time     : 112 ms
* @memory   : 17452 KB
* @state    : 완료
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Data
{
	string strWord;
	int iLength;
	int iCount;
};

bool compare(Data A, Data B)
{
	if (A.iCount == B.iCount)
	{
		if (A.iLength == B.iLength)
			return A.strWord < B.strWord;
		else
			return A.iLength > B.iLength;
	}
	else
		return A.iCount > B.iCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> mapCount;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Word;
		cin >> Word;
		if (Word.size() < M)
			continue;
		mapCount[Word]++;
	}

	vector<Data> vecDatas;
	for (auto& pair : mapCount)
	{
		Data d;
		d.strWord = pair.first;
		d.iLength = pair.first.size();
		d.iCount = pair.second;
		vecDatas.push_back(d);
	}

	sort(vecDatas.begin(), vecDatas.end(), compare);

	for (int i = 0; i < vecDatas.size(); ++i)
		cout << vecDatas[i].strWord << "\n";

	return 0;
}
