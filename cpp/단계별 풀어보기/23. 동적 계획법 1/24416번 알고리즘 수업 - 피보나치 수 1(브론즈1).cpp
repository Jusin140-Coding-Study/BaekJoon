/*
* @title    : 24416�� �˰��� ���� - �Ǻ���ġ �� 1(�����1)
* @content  : ���� ��ȹ�� 1
* @author   : �յ���
* @date     : 240813
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
	
	int DP[41] = { 0, 1, 1, };

	int N;
	cin >> N;

	int DP_Count = 0;
	for (int i = 3; i <= N; ++i)
	{
		++DP_Count;
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N] << " " << DP_Count;

	return 0;
}
