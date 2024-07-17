#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b);

// �ּҰ���� ����
// �� A�� B�� �־����� ��, [ (A * B) / �ִ����� = �ּҰ���� ]
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long A = 0; long B = 0;
	cin >> A >> B;

	int Divisor = gcd(A, B);

	for (int i = 0; i < Divisor; ++i)
		cout << 1;

	return 0;
}

long gcd(long a, long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}