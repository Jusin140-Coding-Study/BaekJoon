/*
* @title    : 11758번 CCW(골드5)
* @content  : 기하
* @author   : 손동찬
* @date     : 240811
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

	int X_1, X_2, X_3;
	int Y_1, Y_2, Y_3;

	cin >> X_1 >> Y_1 >> X_2 >> Y_2 >> X_3 >> Y_3;

	int Result = (X_1 * Y_2 + X_2 * Y_3 + X_3 * Y_1) - (X_2 * Y_1 + X_3 * Y_2 + X_1 * Y_3);

	if (Result < 0) cout << -1;
	else if (Result > 0) cout << 1;
	else cout << 0;

	return 0;
}