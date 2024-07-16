/*
* @title    : 11689번 GCD(n, k) = 1(골드1)
* @content  : 정수론
* @author   : 손동찬
* @date     : 240716
* @time     : 8 ms
* @memory   : 2032 KB
* @state    : 완료
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	long long iResult = N;
	for (long long i = 2; i <= sqrt(N); ++i)
	{
		if (N % i != 0)
			continue;

		iResult -= (iResult / i);

		while (N % i == 0)
			N /= i;
	}

	if (N > 1)
		iResult -= (iResult / N);
	
	cout << iResult;

	return 0;
}
