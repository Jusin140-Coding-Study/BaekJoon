/*
* @title    : 11726�� 2��n Ÿ�ϸ�(�ǹ�3)
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

#define MOD 10007

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> DP(N + 1);
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; ++i)
		DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;

	cout << DP[N];

	return 0;
}