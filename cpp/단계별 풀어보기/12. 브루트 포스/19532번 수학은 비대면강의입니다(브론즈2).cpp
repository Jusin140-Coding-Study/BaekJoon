/*
* @title    : 19532번 수학은 비대면강의입니다(브론즈2)
* @content  : 브루트 포스
* @author   : 손동찬
* @date     : 240710
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

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; ++x)
	{
		for (int y = -999; y <= 999; ++y)
		{
			if (a * x + b * y == c && d * x + e * y == f)
			{
				cout << x << " " << y << "\n";
				break;
			}
		}
	}

	return 0;
}