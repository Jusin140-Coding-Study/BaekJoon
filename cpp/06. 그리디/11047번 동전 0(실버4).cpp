/*
* @title    : 11047�� ���� 0(�ǹ�4)
* @content  : �׸���
* @author   : �յ���
* @date     : 240715
* @time     : 0ms
* @memory   : 2020 KB
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

	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = N - 1; i >= 0; --i)
		cin >> v[i];
	
	int iCount = 0;
	int a=0;
	while (K > 0 && a < N)
	{
		int iNum = K / v[a];

		if (iNum != 0)
		{
			iCount += iNum;
			K = K % v[a];
		}
		a++;
	}

	cout << iCount;

	return 0;
}
