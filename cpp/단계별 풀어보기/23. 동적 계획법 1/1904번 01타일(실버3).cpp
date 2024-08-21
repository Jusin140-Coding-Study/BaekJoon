/*
* @title    : 1904�� 01Ÿ��(�ǹ�3)
* @content  : ���� ��ȹ�� 1
* @author   : �յ���
* @date     : 240807
* @time     : 4 ms
* @memory   : 5928 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 15746

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	vector<int> DP(N + 1);
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; ++i)
		DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;

	cout << DP[N];

	return 0;
}
