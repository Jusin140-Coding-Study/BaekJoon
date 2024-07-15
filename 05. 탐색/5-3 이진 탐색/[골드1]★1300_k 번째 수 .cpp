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
	int high = K; // B[K]는 2차원 배열에서 항상 k보다 작다.

	while (low < high)
	{
		int mid = (low + high) / 2;
		int count = 0;

		for (int i = 1; i <= N; ++i)
		{
			// i행에서 mid 보다 낮은 수의 개수를 모두 합한다.
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