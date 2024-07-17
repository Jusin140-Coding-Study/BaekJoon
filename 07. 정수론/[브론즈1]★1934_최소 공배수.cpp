#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

// 최소공배수 계산법
// 수 A와 B가 주어졌을 때, [ (A * B) / 최대공약수 = 최소공배수 ]
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

// 최대공약수를 구하는 함수
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