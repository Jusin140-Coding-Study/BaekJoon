/*
* @title    : 17103�� ������ ��Ƽ��(�ǹ�2)
* @content  : ���, ����� �Ҽ� 2
* @author   : �յ���
* @date     : 240717
* @time     : 56 ms
* @memory   : 2264 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define Max 1000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecPrimeDatas(Max + 1, true);
	vecPrimeDatas[0] = false;
	vecPrimeDatas[1] = false;
	for (int i = 2; i <= sqrt(Max); ++i)
	{
		if (vecPrimeDatas[i])
		{
			int a = 2;
			while (i * a <= Max)
			{
				if (vecPrimeDatas[i * a])
					vecPrimeDatas[i * a] = false;
	
				a++;
			}
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int iTestCase;
		cin >> iTestCase;
		int iCount = 0;
		for (int j = 2; j <= (iTestCase/2); ++j)
		{
			if (vecPrimeDatas[j] && vecPrimeDatas[iTestCase - j])
				iCount++;
		}
		cout << iCount <<"\n";
	}

	return 0;
}
