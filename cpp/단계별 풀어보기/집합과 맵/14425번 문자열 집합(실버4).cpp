/*
* @title    : 14425번 문자열 집합(실버4)
* @content  : 집합과 맵
* @author   : 손동찬
* @date     : 240714
* @time     : 52 ms
* @memory   : 7768 KB
* @state    : 완료
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_set<string> usWords(N);
	for (int i = 0; i < N; ++i)
	{
		string a;
		cin >> a;
		usWords.insert(a);
	}

	int iCount = 0;
	for (int i = 0; i < M; ++i)
	{
		string a;
		cin >> a;
		if (usWords.find(a) != usWords.end())
			iCount++;
	}

	cout << iCount;

	return 0;
}
