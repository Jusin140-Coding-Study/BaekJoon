/*
* @title    : 1436�� ��ȭ���� ��(�ǹ�5)
* @content  : ���Ʈ ����
* @author   : �յ���
* @date     : 240713
* @time     : 32 ms
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
	int iCount = 0;
	int iResult = 0;
	for (int i = 666; ; ++i)
	{
		int iNum = i;
		int iSixCount = 0;

		while (iNum > 0)
		{
			if (iNum % 10 == 6)
				iSixCount++;

			else iSixCount = 0;

			if (iSixCount == 3)
			{
				iCount++;
				break;
			}
			iNum /= 10;
		}	
		
		if (iCount == N)
		{
			iResult = i;
			break;
		}
	}

	cout << iResult <<"\n";

	return 0;
}