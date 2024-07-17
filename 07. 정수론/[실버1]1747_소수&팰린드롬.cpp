#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �� ��̴� �� ��
	// ��ü ������ N ~ �鸸���� �ΰ� �Ǻ��ϰ� �־���.
	// �鸸���� ū �� �߿��� �Ҽ��̸鼭 �Ӹ������ ���� ����ؾ� ��

	// 1. �����佺�׳׽��� 1�� �Ÿ�
	// 2. �Ӹ�������� �Ǻ�
	// 3. �´ٸ� ���
	int N = 0;
	cin >> N;

	vector<bool> V(10000001, true);
	V[0] = false;
	V[1] = false;

	// �����佺�׳׽��� ü
	for (int i = 2; i <= sqrt(10000001); ++i)
	{
		if (false == V[i]) continue;

		for (int j = 2 * i; j <= 10000000; j += i)
			V[j] = false;
	}

	for (int i = N; i < 10000001; ++i)
	{
		if (false == V[i]) continue;

		string strNum = to_string(i);

		int start = 0;
		int end = strNum.size() - 1;

		bool bEqual = true;

		while (start < end)
		{
			if (strNum[start] != strNum[end])
			{
				bEqual = false;
				break;
			}

			start++;
			end--;
		}

		if (bEqual)
		{
			cout << strNum << "\n";
			break;
		}
	}

	return 0;
}