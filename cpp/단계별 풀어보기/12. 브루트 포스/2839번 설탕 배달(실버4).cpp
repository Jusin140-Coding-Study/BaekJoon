/*
* @title    : 2839�� ���� ���(�ǹ�4)
* @content  : ���Ʈ ����
* @author   : �յ���
* @date     : 240713
* @time     : 0ms
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

	int N;
	cin >> N;

	int iFive = N/5;
	int iTotal = -1;
	for (int i = iFive; i >= 0; --i)
	{
		if ((N - 5 * i) % 3 == 0)
		{
			iTotal = (N - 5 * i) / 3 + i;
			break;
		}
	}

	cout << iTotal << "\n";

	return 0;
}