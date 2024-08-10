/*
* @title    : 1463�� 1�� �����(�ǹ�3)
* @content  : ���� ��ȹ��
* @author   : �յ���
* @date     : 240807
* @time     : 4 ms
* @memory   : 5928 KB
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
	
	int N;
	cin >> N;
	vector<int> DP(N + 1);

	DP[1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		DP[i] = DP[i - 1] + 1;

		if (!(i % 2))
			DP[i] = min(DP[i], DP[i / 2] + 1);

		if (!(i % 3))
			DP[i] = min(DP[i], DP[i / 3] + 1);
	}

	cout << DP[N];

	return 0;
}