/*
* @title    : 25192번 인사성 밝은 곰곰이(실버4)
* @content  : 심화 2
* @author   : 손동찬
* @date     : 240723
* @time     : 36 ms
* @memory   : 8312 KB
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

	unordered_set<string> usData;
	int N;
	cin >> N;
	int iCount = 0;
	for (int i = 0; i < N; ++i)
	{
		string a;
		cin >> a;
		if (a == "ENTER")
			unordered_set<string>().swap(usData);

		else
		{
			if (usData.find(a) == usData.end())
			{
				++iCount;
				usData.emplace(a);
			}
		}	
	}
	cout << iCount;

	return 0;
}
