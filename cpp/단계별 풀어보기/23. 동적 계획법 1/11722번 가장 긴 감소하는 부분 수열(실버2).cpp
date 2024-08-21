/*
* @title    : 11722�� ���� �� �����ϴ� �κ� ����(�ǹ�2)
* @content  : ���� ��ȹ�� 1
* @author   : �յ���
* @date     : 240820
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> Datas(N);
	vector<int> DP(N, 1);

	for (int i = 0; i < N; ++i)
		cin >> Datas[i];

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Datas[i] >= Datas[j])
				continue;

			DP[i] = max(DP[i], DP[j] + 1);
		}
	}

	cout << *max_element(DP.begin(), DP.end());

	return 0;
}
