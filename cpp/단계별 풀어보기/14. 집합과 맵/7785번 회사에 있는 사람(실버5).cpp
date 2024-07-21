/*
* @title    : 7785번 회사에 있는 사람(실버5)
* @content  : 집합과 맵
* @author   : 손동찬
* @date     : 240714
* @time     : 84 ms
* @memory   : 9948 KB
* @state    : 완료
*/
#include <iostream>
#include <map>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	map<string, bool,greater<>> mLog;
	for (int i = 0; i < n; ++i)
	{
		string Name, Commute;
		cin >> Name >> Commute;

		if (Commute == "enter")
			mLog[Name] = true;
		else
			mLog[Name] = false;
	}
	
	for (const auto& pair : mLog)
		if (pair.second)
			cout << pair.first <<"\n";


	return 0;
}
