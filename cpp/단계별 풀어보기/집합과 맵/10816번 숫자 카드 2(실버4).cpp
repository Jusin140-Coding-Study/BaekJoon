/*
* @title    : 10816번 숫자 카드 2(실버4)
* @content  : 집합과 맵
* @author   : 손동찬
* @date     : 240715
* @time     : 312 ms
* @memory   : 23304 KB
* @state    : 완료
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<int, int> umNumDatas;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;
		umNumDatas[iNum]++;
	}
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int iNum;
		cin >> iNum;
		if (umNumDatas.find(iNum) == umNumDatas.end())
			cout << "0 ";
		else
			cout << umNumDatas.find(iNum)->second << " ";
	}

	return 0;
}
