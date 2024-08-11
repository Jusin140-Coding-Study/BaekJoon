/*
* @title    : 17387번 선분 교차 2(골드2)
* @content  : 기하
* @author   : 손동찬
* @date     : 240811
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

typedef long long _long;

int CCW(_long _X1, _long _Y1, _long _X2, _long _Y2, _long _X3, _long _Y3)
{
	_long Result = (_X1 * _Y2 + _X2 * _Y3 + _X3 * _Y1) - (_X2 * _Y1 + _X3 * _Y2 + _X1 * _Y3);
	if (Result > 0) return 1;
	if (Result < 0) return -1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	_long X1, X2, X3, X4;
	_long Y1, Y2, Y3, Y4;

	cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;

	int Result1 = CCW(X1, Y1, X2, Y2, X3, Y3);
	int Result2 = CCW(X1, Y1, X2, Y2, X4, Y4);
	int Result3 = CCW(X3, Y3, X4, Y4, X1, Y1);
	int Result4 = CCW(X3, Y3, X4, Y4, X2, Y2);


	if (Result1 == 0 && Result2 == 0 && Result3 == 0 && Result4 == 0 )
	{
		if(min(X1, X2) <= max(X3, X4) && min(X3, X4) <= max(X1, X2) &&
			min(Y1, Y2) <= max(Y3, Y4) && min(Y3, Y4) <= max(Y1, Y2))
			cout << 1;
		else
			cout << 0;
	}
	else if ((Result1 * Result2 <= 0) && (Result3 * Result4 <= 0))
		cout << 1;

	else cout << 0;

	return 0;
}