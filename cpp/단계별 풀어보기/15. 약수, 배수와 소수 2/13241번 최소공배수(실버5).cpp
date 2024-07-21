/*
* @title    : 13241번 최소공배수(실버5)
* @content  : 약수, 배수와 소수 2
* @author   : 손동찬
* @date     : 240716
* @time     : 4 ms
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

	long long a, b;
	cin >> a >> b;
	long long iS = min(a, b);
	long long iB = max(a, b);
	int sMul = 1, bMul = 1;

	a = iS * sMul;
	b = iB * bMul;
	while (a != b)
	{
		if (a < b)
			sMul++;
		else
			bMul++;

		a = iS * sMul;
		b = iB * bMul;
	}
	cout << a << "\n";
	
	return 0;
}
