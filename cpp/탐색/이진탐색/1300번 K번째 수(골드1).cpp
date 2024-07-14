/*
* @title    : 1300�� K��° ��(���1)
* @content  : ����Ž��
* @author   : �յ���
* @date     : 240714
* @time     :  ms
* @memory   :  KB
* @state    : �Ϸ�
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k;
	cin >> N >> k;
	
	int iStart = 1, iEnd = k;
	int iResult = 0;
	while (iStart <= iEnd)
	{
		int iMiddle = (iStart + iEnd) / 2;
		int iMinCount = 0;
		for (int i = 1; i <= N; ++i)
			iMinCount += min(iMiddle /i, N);

		if (iMinCount < k)
			iStart = iMiddle + 1;
		else
		{
			iResult = iMiddle;
			iEnd = iMiddle - 1;
		}
	}
	cout << iResult;
	return 0;
}