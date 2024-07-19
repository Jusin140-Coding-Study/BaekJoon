/*
* @title    : 1929�� �Ҽ� ���ϱ�(�ǹ�3)
* @content  : ������
* @author   : �յ���
* @date     : 2407156
* @time     : 20 ms
* @memory   : 2260 KB
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

	int M, N;
	cin >> M >> N;
	vector<bool> vecNumbers(N+1);
	for (int i = 2; i <= N; ++i)
		vecNumbers[i] = true;
	
	for (int i = 2; i * i <= N; ++i)
	{
		if (!vecNumbers[i])
			continue;

		for (int j = i*2; j <= N; j += i)
		{
			if (vecNumbers[j])
				vecNumbers[j] = false;
		}
	}

	for (int i = M; i <= N; ++i)
		if (vecNumbers[i])
			cout << i << "\n";

	return 0;
}
