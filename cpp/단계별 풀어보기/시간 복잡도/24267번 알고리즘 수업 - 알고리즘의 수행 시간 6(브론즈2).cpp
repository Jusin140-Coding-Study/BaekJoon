/*
* @title    : 24267번 알고리즘 수업 - 알고리즘의 수행 시간 6(브론즈2)
* @content  :
* @author   : 손동찬
* @date     : 240709
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

	long long n;
	cin >> n;
	long long iResult = 0;
	for (long long i = 1; i < n - 1; ++i)
		iResult += i * (i + 1) / 2;

	cout << iResult << "\n" << "3";

	return 0;
}