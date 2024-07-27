/*
* @title    : 26069번 붙임성 좋은 총총이(실버4)
* @content  : 심화 2
* @author   : 손동찬
* @date     : 240724
* @time     : 0ms
* @memory   : 2160 KB
* @state    : 완료
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<string> usNames;
	usNames.emplace("ChongChong");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string A, B;
		cin >> A >> B;
		if (usNames.find(A) != usNames.end() || usNames.find(B) != usNames.end())
		{
			usNames.emplace(A);
			usNames.emplace(B);
		}
	}
	
	cout << usNames.size();

	return 0;
}
