/*
* @title    : 4948�� ����Ʈ�� ����(�ǹ�2)
* @content  : ���, ����� �Ҽ� 2
* @author   : �յ���
* @date     : 240717
* @time     : 12 ms
* @memory   : 2172 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define Max 246912

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecPrimeDatas(Max+1, true);
	vecPrimeDatas[0] = false;
	vecPrimeDatas[1] = false;
	for (int i = 2; i <= sqrt(Max); ++i)
	{
		if (vecPrimeDatas[i])
		{
			int a = 2;
			while (i*a <= Max)
			{
				if (vecPrimeDatas[i * a])
					vecPrimeDatas[i * a] = false;

				a++;
			}
		}
	}

	int N;
	cin >> N;
	while (N)
	{
		int iCount = 0;
		for (int i = N + 1; i <= 2 * N; ++i)
			if (vecPrimeDatas[i]) iCount++;
		
		cout << iCount << "\n";
		cin >> N;
	}

	return 0;
}
