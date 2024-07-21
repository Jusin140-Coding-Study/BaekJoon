/*
* @title    : 1934번 최소공배수(브론즈1)
* @content  : 약수, 배수와 소수 2
* @author   : 손동찬
* @date     : 240715
* @time     : 68 ms
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
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int a, b;
		cin >> a >> b;
		int iS = min(a, b);
		int iB = max(a, b);
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
	}


	return 0;
}
