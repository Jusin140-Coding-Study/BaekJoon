/*
* @title    : 2193�� ��ģ��(�ǹ�3)
* @content  : ���� ��ȹ��
* @author   : �յ���
* @date     : 240807
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

	int N;
	cin >> N;

	vector<long long> DP(N + 1);
	DP[1] = 1;
	DP[2] = 1;

	for (int i = 2; i <= N; ++i)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[N];

	return 0;
}