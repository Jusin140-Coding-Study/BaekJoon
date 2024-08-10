/*
* @title    : 1947�� ���� ����(���3)
* @content  : ����
* @author   : �յ���
* @date     : 240806
* @time     :  ms
* @memory   :  KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<long long> v(N + 1);

	v[1] = 0;
	v[2] = 1;

	for (int i = 3; i <= N; ++i)
		v[i] = ((i - 1) * (v[i - 1] + v[i - 2])) % MOD;
	
	cout << v[N];

	return 0;
} 