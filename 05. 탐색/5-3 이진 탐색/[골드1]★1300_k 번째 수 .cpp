#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int K = 0;

	cin >> N;
	cin >> K;
	
	int low = 1;
	int high = K; // B[K]�� 2���� �迭���� �׻� k���� �۴�.

	while (low < high)
	{
		int mid = (low + high) / 2;
		int count = 0;

		for (int i = 1; i <= N; ++i)
		{
			// i�࿡�� mid ���� ���� ���� ������ ��� ���Ѵ�.
			count += min(mid / i, N);
		}

		if (count < K)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}

	cout << high;
}