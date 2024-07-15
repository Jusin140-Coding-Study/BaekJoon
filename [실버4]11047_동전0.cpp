#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �׸��� �˰���
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �׸��� �˰��� ���� ����
	// 1. �� ���� : ���� ���¿��� ���� �ּ��̶�� �����Ǵ� �ظ� �����Ѵ�.
	// 2. ������ �˻� : ���� ������ �ذ� ��ü ������ ���� ���ǿ� ����� �ʴ��� �˻��Ѵ�.
	// 3. �� �˻� : ������� ���°��� �� ������ ��ü ������ �ذ��� �� �ִ��� �˻��Ѵ�.
	//				��ü ������ �ذ����� ���Ѵٸ� 1.�� ���ư� ���� ������ �ݺ��Ѵ�.

	// N : ���� ������ ����
	// K : ����� �ϴ� �ݾ�
	int N = 0; int K = 0; int Result = 0;
	cin >> N >> K;

	vector<int> V(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> V[i];

	reverse(V.begin(), V.end());

	for (int i = 0; i < N; ++i)
	{
		// �迭�� ����ִ� ������ �ݾ��� K���� �۴ٸ�?
		if (V[i] < K)
		{
			Result += K / V[i];
			K = K % V[i];
		}

		// if (K == 0) break;
	}

	cout << Result;
}