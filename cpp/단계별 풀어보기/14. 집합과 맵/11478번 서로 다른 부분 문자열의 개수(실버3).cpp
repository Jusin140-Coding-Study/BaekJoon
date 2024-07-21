/*
* @title    : 11478번 서로 다른 부분 문자열의 개수(실버3)
* @content  : 집합과 맵
* @author   : 손동찬
* @date     : 240715
* @time     : 520 ms
* @memory   : 209864 KB
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
	unordered_set<string> usParts;
	string A;
	cin >> A;
	for (int i = 0; i < A.size(); ++i)
	{
		string Temp = "";
		for (int j = i; j < A.size(); ++j)
		{
			Temp += A[j];
			usParts.insert(Temp);
		}
	}

	cout << usParts.size();

	return 0;
}
