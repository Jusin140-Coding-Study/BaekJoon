/*
* @title    : 19532�� ������ ���鰭���Դϴ�(�����2)
* @content  : ���Ʈ ����
* @author   : �յ���
* @date     : 240710
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