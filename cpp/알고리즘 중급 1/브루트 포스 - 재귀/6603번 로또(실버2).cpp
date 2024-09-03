/*
* @title    : 6603�� �ζ�(�ǹ�2)
* @content  : ���Ʈ ���� - ���
* @author   : �յ���
* @date     : 240824
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reset(vector<int>& _vecChoice)
{
	for (int i = 0; i < 6; ++i)
		_vecChoice[i] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	while (N)
	{
		vector<int> vecNum(N);
		for (int i = 0; i < N; ++i)
			cin >> vecNum[i];

		vector<int> vecChoice(N, 0);
		Reset(vecChoice);

		while (1)
		{
			for (int i = 0; i < N; ++i)
			{
				if (vecChoice[i])
					cout << vecNum[i] << " ";
			}
			cout << "\n";
			if (!prev_permutation(vecChoice.begin(), vecChoice.end()))
				break;
		}
		cout << "\n";
		cin >> N;
	}

	return 0;
}
