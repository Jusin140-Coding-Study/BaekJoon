/*
* @title    : 10872번 팩토리얼(브론즈3)
* @content  : 조합론
* @author   : 손동찬
* @date     : 240722
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Result = 1;
	for (int i = 1; i <= N; ++i)
		Result *= i;
	
	cout << Result;

	return 0;
}
