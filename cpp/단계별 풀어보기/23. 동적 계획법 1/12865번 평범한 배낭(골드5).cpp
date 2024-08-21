/*
* @title    : 12865�� ����� �賶(���5)
* @content  : ���� ��ȹ�� 1
* @author   : �յ���
* @date     : 240821
* @time     :  ms
* @memory   :  KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>

using namespace std; 

typedef pair<int, int> Data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	vector<Data> Datas(N+1); 
	vector<vector<int>> DP(K+1, vector<int>(N+1, 0)); 
	
	for (int i = 1; i <= N; ++i)
		cin >> Datas[i].first >> Datas[i].second;
	
	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int Weight = Datas[j].first;
			int value = Datas[j].second;
			if (i >= Weight)
				DP[i][j] = max(DP[i - Weight][j - 1] + value, DP[i][j - 1]);
			else
				DP[i][j] = DP[i][j - 1];
		}
	}

	cout << DP[K][N];
	
	return 0;
}
