#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ���Ϸ� ��
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n = 0;
	cin >> n;

	long Result = n;

	for (long i = 2; i <= sqrt(n); ++i)
	{
		// ���� i�� ���μ����
		if (n % i == 0)
		{
			Result = Result - Result / i; // ����� ������Ʈ

			// �ش� ���μ��� ������ ������ ������
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}

	// ���μ� �ϳ��� ������ ���
	if (n > 1)
		Result = Result - Result / n; // ����� ������Ʈ

	cout << Result;
}