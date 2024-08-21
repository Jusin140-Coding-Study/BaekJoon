/*
* @title    : 2579�� ��� ������(�ǹ�3)
* @content  : ���� ��ȹ�� 1
* @author   : �յ���
* @date     : 240819
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
	vector<int> Datas(N + 1, 0);
	vector<int> DP(N + 1, 0);
	for (int i = 1; i <= N; ++i)
		cin >> Datas[i];

	DP[1] = Datas[1];
	DP[2] = Datas[1] + Datas[2];

	for (int i = 3; i <= N; ++i)
		DP[i] = max(DP[i - 2] + Datas[i], DP[i - 3] + Datas[i - 1] + Datas[i]);
	
	cout << DP[N];

	return 0;
}
