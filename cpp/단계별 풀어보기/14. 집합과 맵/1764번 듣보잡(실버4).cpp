/*
* @title    : 1764번 듣보잡(실버4)
* @content  : 집합과 맵
* @author   : 손동찬
* @date     : 240715
* @time     : 32 ms
* @memory   : 7512 KB
* @state    : 완료
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_set<string> usNames;
	for (int i = 0; i < N; ++i)
	{
		string strName;
		cin >> strName;
		usNames.insert(strName);
	}
	vector<string> vecNames;
	int iCount =0;
	for (int i = 0; i < M; ++i)
	{
		string strName;
		cin >> strName;
		if (usNames.find(strName) == usNames.end())
			continue;

		iCount++;
		vecNames.push_back(strName);
	}
	sort(vecNames.begin(), vecNames.end());

	cout << iCount << "\n";
	for (int i = 0; i < vecNames.size(); ++i)
	{
		cout << vecNames[i] << "\n";
	}
	return 0;
}
