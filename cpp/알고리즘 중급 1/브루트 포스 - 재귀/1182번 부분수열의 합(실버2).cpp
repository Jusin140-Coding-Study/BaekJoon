/*
* @title    : 1182�� �κм����� ��(�ǹ�2)
* @content  : ���Ʈ ���� - ���
* @author   : �յ���
* @date     : 240824
* @time     : 48 ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecChoice;

void Reset(int _iNum)
{
	for (int i = 0; i < _iNum; ++i)
		vecChoice[i] = 1;
	for (int i = _iNum; i < vecChoice.size(); ++i)
		vecChoice[i] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;
	vector<int> vecNums(N);
	vecChoice.resize(N, 0);
	
	for (int i = 0; i < N; ++i)
		cin >> vecNums[i];
	
	int Count = 0;
	for (int i = 1; i <= N; ++i)
	{
		Reset(i);

		while (1)
		{
			int Sum = 0;

			for (int j = 0; j < N; ++j)
			{
				if (vecChoice[j])
					Sum += vecNums[j];
			}

			if (Sum == S)
				++Count;

			if (!prev_permutation(vecChoice.begin(), vecChoice.end()))
				break;
		}
	}

	cout << Count;

	return 0;
}
