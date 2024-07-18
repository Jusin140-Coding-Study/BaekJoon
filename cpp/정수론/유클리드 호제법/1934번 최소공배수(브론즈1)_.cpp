/*
* @title    : 1934번 최소공배수(브론즈1)
* @content  : 유클리드 호제법
* @author   : 손동찬
* @date     : 240718
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

static int GCD(int A, int B)
{
	int iMax = max(A, B);
	int iMin = min(A, B);

	while (iMax % iMin != 0)
	{
		int Temp = iMin;
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
	int T;
	cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << (a*b) / GCD(a, b) <<"\n";
	}
	return 0;
}
