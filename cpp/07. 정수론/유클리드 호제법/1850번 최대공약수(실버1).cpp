/*
* @title    : 1850번 최대공약수(실버1)
* @content  : 유클리드 호제법
* @author   : 손동찬
* @date     : 240718
* @time     : 116 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

long long GCD(long long A, long long B)
{
	long long iMax = max(A, B);
	long long iMin = min(A, B);

	while (iMax % iMin != 0)
	{
		long long Temp = iMin;
		iMin = iMax % iMin;
		iMax = Temp;
	}

	return iMin;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;
	long long iNum = GCD(A, B);

	for(long long i =0; i < iNum; ++i)
		cout << "1";

	return 0;
}
