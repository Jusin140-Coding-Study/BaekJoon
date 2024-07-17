#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

// �ּҰ���� ����
// �� A�� B�� �־����� ��, [ (A * B) / �ִ����� = �ּҰ���� ]
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A = 0; int B = 0; int Result = 0;
	int T = 0;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> A >> B;

		Result = A * B / gcd(A, B);
		cout << Result << "\n";
	}

	return 0;
}

// �ִ������� ���ϴ� �Լ�
int gcd(int a, int b)
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