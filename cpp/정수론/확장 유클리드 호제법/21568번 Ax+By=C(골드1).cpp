/*
* @title    : 21568번 Ax+By=C(골드1)
* @content  : 확장 유클리드 호제법
* @author   : 손동찬
* @date     : 240718
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int GDC(int _A, int _B)
{
	int iMax = max(_A, _B);
	int iMin = min(_A, _B);
	
	while (iMax % iMin)
	{
		int Temp = iMin;
		iMin = iMax % iMin;
		iMax = Temp;
	}
	
	return iMin;
}

vector<int> Extension_Euclidean(int _A, int _B)
{
	vector<int> vecTemp(2);

	if (!_B)
	{
		vecTemp[0] = 1;
		vecTemp[1] = 0;
		return vecTemp;
	}

	int Quo = _A/_B;
	vector<int> v = Extension_Euclidean(_B, _A %_B);

	vecTemp[0] = v[1];
	vecTemp[1] = v[0] - (v[1] * Quo);

	return vecTemp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	int iGCD = GDC(A,B);
	if (C % iGCD)
	{
		cout << "-1";
		return 0;
	}
	int Mul = C/iGCD;
	vector<int> vecResult = Extension_Euclidean(A, B);
	cout << vecResult[0] * Mul << " " << vecResult[1] * Mul;
	return 0;
}
