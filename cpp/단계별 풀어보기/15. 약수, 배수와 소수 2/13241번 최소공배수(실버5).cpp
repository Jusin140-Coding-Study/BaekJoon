/*
* @title    : 13241�� �ּҰ����(�ǹ�5)
* @content  : ���, ����� �Ҽ� 2
* @author   : �յ���
* @date     : 240716
* @time     : 4 ms
* @memory   : 2020 KB
* @state    : �Ϸ�
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
