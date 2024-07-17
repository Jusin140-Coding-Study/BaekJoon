#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 오일러 피
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
		// 만약 i가 소인수라면
		if (n % i == 0)
		{
			Result = Result - Result / i; // 결과값 업데이트

			// 해당 소인수가 없어질 때까지 나눈다
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}

	// 소인수 하나가 누락된 경우
	if (n > 1)
		Result = Result - Result / n; // 결과값 업데이트

	cout << Result;
}