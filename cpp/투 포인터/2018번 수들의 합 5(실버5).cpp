/*
* @title    : 2018�� ������ �� 5(�ǹ�5)
* @content  :
* @author   : �յ���
* @date     : 240709
* @time     : 28 ms
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
	int iCount = 1;
	int iStartIndex = 1;
	int iEndIndex = 1;
	int iSum = 1;

	while (iEndIndex != N)
	{
		if (iSum == N)
		{
			iCount++;
			iEndIndex++;
			iSum += iEndIndex;
		}
		else if (iSum > N)
		{
			iSum -= iStartIndex;
			iStartIndex++;	
		}
		else
		{
			iEndIndex++;
			iSum += iEndIndex;
		}
	}

	cout << iCount << "\n";

	return 0;
}