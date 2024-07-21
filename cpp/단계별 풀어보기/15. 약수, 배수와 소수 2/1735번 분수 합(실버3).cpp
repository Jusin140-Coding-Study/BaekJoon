/*
* @title    : 1735�� �м� ��(�ǹ�3)
* @content  : ���, ����� �Ҽ� 2
* @author   : �յ���
* @date     : 240717
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>

using namespace std;

int GCD(int A, int B)
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

	int A1, B1, A2, B2;
	cin >> A1 >> B1 >> A2 >> B2;

	int iLCM = (B1 * B2) / GCD(B1, B2);

	int a = iLCM / B1;
	int b = iLCM / B2;
	int c = (A1 * a) + (A2 * b);
	int d = GCD(c, iLCM);

	cout << c / d << " " << iLCM / d;

	return 0;
}
