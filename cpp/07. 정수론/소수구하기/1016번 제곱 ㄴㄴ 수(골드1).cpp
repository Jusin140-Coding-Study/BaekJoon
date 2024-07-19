/*
* @title    : 1016�� ���� ���� ��(���1)
* @content  : ������
* @author   : �յ���
* @date     : 240716
* @time     : 16 ms
* @memory   : 2264 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iMin, iMax;
	cin >> iMin >> iMax;
	vector<bool> vecNums(iMax-iMin+1, true);

	for (long long i = 2; i * i <= iMax; ++i)
	{		
		long long pow = i * i;

		long long iStart = iMin / pow;
		if (iMin % pow != 0) iStart++;

		for (long long j = iStart; pow * j <= iMax; ++j)
		{
			if (vecNums[pow*j - iMin])
				vecNums[pow*j - iMin] = false;
		}
	}

	int iCount = 0;
	for (auto b : vecNums)
		if(b) iCount++;
			
	cout << iCount;

	return 0;
}
